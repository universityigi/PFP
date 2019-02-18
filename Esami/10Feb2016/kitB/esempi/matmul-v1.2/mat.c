/* ============================================================================
 *  mat.c
 * ============================================================================

 *  Author:         (c) 2013-2015 Camil Demetrescu
 *  License:        See the end of this file for license information
 *  Created:        April 27, 2013

 *  Last changed:   $Date: 2015/12/04 10:04:36 $
 *  Changed by:     $Author: demetres $
 *  Revision:       $Revision: 1.200 $
*/

#include "mat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>
#include <assert.h>
#include <pthread.h>

#define AVX2    1
#define SSE2    2

// config
#define VERSION AVX2    // select family of intrinsics (SSE2 or AVX2)
typedef int T;          // configure base type

#if VERSION == AVX2
#define STEP    8
#define VEC     __m256i
#define ADD     _mm256_add_epi32
#define MUL     _mm256_mullo_epi32
#define LOAD    _mm256_loadu_si256
#define STORE   _mm256_storeu_si256
#define SET     _mm256_set_epi32
#elif VERSION == SSE2
#define STEP    4
#define VEC     __m128i
#define ADD     _mm_add_epi32
#define MUL     _mm_mullo_epi32
#define LOAD    _mm_loadu_si128
#define STORE   _mm_storeu_si128
#define SET     _mm_set_epi32
#else
#error Undefined vectorization
#endif

struct mat {
    T** v;
    unsigned n;
};

// prototypes
static void mat_mul_ijk(T** a, T** b, T** c, unsigned n);
static void mat_mul_ijk_sum(T** a, T** b, T** c, unsigned n);
static void mat_mul_ijk_trans(T** a, T** b, T** c, unsigned n);
static void mat_mul_ikj(T** a, T** b, T** c, unsigned n);
static void mat_mul_ikj_vec(T** a, T** b, T** c, unsigned n);
static void mat_mul_ijk_trans_vec(T** a, T** b, T** c, unsigned n);
static void mat_mul_ikj_vec_2thread(T** a, T** b, T** c, unsigned n);
static void mat_mul_ikj_vec_4thread(T** a, T** b, T** c, unsigned n);

// code versions
static void (*mat_mul_ver[])(T** a, T** b, T** c, unsigned n) = {
    mat_mul_ijk,
    mat_mul_ijk_sum,
    mat_mul_ijk_trans,
    mat_mul_ikj,
    mat_mul_ikj_vec,
    mat_mul_ijk_trans_vec,
    mat_mul_ikj_vec_2thread,
    mat_mul_ikj_vec_4thread
};

static char* mat_mul_desc[] = {
    "triple loop ijk",
    "triple loop ijk with accumulator",
    "triple loop ijk with accumulator and transposed b",
    "triple loop ikj",
    "triple loop ikj and vectorization",
    "triple loop ijk with accumulator, transposed b, and vectorization",
    "triple loop ikj, vectorization, and 2 threads",
    "triple loop ikj, vectorization, and 4 threads"
};


// ---------------------------------------------------------------------
// mat_new
// ---------------------------------------------------------------------
// create new n x n matrix
mat* mat_new(unsigned n) {
    long i;
    mat* m = malloc(sizeof(mat));
    m->v = malloc(n*sizeof(T*));
    m->n = n;
    for (i=0; i<n; i++) m->v[i] = malloc(n*sizeof(T));
    return m;
}


// ---------------------------------------------------------------------
// mat_delete
// ---------------------------------------------------------------------
// delete matrix
void mat_delete(mat* m) {
    long i;
    for (i=0; i<m->n; i++) free(m->v[i]);
    free(m->v);
    free(m);
}


// ---------------------------------------------------------------------
// mat_mul_get_desc
// ---------------------------------------------------------------------
// get version description
char* mat_mul_get_desc(int ver) {
    return mat_mul_desc[ver];
}


// ---------------------------------------------------------------------
// mat_init
// ---------------------------------------------------------------------
// init matrix with random values
void mat_init(mat* a, int seed, int max) {
    long i, j;
    srand(seed);
    for (i=0; i<a->n; i++)
        for (j=0; j<a->n; j++) a->v[i][j] = rand() % max;
}


// ---------------------------------------------------------------------
// mat_mul_check
// ---------------------------------------------------------------------
// check correctness
int mat_mul_check(mat* a, mat* b, mat* c) {

    if (a->n != b->n || a->n != c->n) return 0;

    long i, j, k;

    for (i = 0; i < c->n; i++)
        for (j = 0; j < c->n; j++) {
            T sum = 0;
            for (k = 0; k < c->n; k++)
                sum += a->v[i][k] * b->v[k][j];

            if (sum != c->v[i][j]) return 0;
        }

    return 1;
}


// ---------------------------------------------------------------------
// mat_mul
// ---------------------------------------------------------------------
// perform matrix multiplication using code version ver
int mat_mul(mat* a, mat* b, mat* c, int ver) {
    if (a->n != b->n || a->n != c->n) return -1;
    mat_mul_ver[ver](a->v, b->v, c->v, a->n);
    return 0;
}


// ---------------------------------------------------------------------
// mat_mul_ijk
// ---------------------------------------------------------------------
// perform matrix multiplication
void mat_mul_ijk(T** a, T** b, T** c, unsigned n) {

    long i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) 
                c[i][j] += a[i][k]*b[k][j];
        }
}


// ---------------------------------------------------------------------
// _mat_transpose
// ---------------------------------------------------------------------
// perform matrix transposition
static void _mat_transpose(T** m, unsigned n) {
    long i, j;
    for (i = 0; i<n; i++)
        for (j = i+1; j<n; j++) {
            T temp  = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
}


// ---------------------------------------------------------------------
// mat_mul_ijk_sum
// ---------------------------------------------------------------------
// perform matrix multiplication
static void mat_mul_ijk_sum(T** a, T** b, T** c, unsigned n) {

    long i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            T sum = 0;
            for (k = 0; k < n; k++) 
                sum += a[i][k]*b[k][j];
            c[i][j] = sum;
        }
}


// ---------------------------------------------------------------------
// mat_mul_ijk_trans
// ---------------------------------------------------------------------
// perform matrix multiplication
static void mat_mul_ijk_trans(T** a, T** b, T** c, unsigned n) {

    long i, j, k;

    _mat_transpose(b, n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            T sum = 0;
            for (k = 0; k < n; k++) 
                sum += a[i][k]*b[j][k];
            c[i][j] = sum;
        }

    _mat_transpose(b, n);
}


// ---------------------------------------------------------------------
// mat_mul_ikj
// ---------------------------------------------------------------------
// perform matrix multiplication
void mat_mul_ikj(T** a, T** b, T** c, unsigned n) {

    long i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) c[i][j] = 0;

    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++) {
            T aik = a[i][k];
            for (j = 0; j < n; j++)
                c[i][j] += aik * b[k][j];
        }
}


// ---------------------------------------------------------------------
// mat_mul_ikj_vec
// ---------------------------------------------------------------------
// perform matrix multiplication
void mat_mul_ikj_vec(T** a, T** b, T** c, unsigned n) {

    long i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) c[i][j] = 0;

    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++) {
            T aik = a[i][k];
            for (j = 0; j < n-STEP+1; j+=STEP) {
                #if VERSION == AVX2
                VEC ap = SET(aik,aik,aik,aik,aik,aik,aik,aik);
                #else
                VEC ap = SET(aik,aik,aik,aik);
                #endif
                VEC bp = LOAD((VEC*)&b[k][j]);
                VEC cp = LOAD((VEC*)&c[i][j]);
                bp = MUL(ap,bp);
                cp = ADD(cp,bp);
                STORE((VEC*)&c[i][j], cp);
            }
            for (; j<n; j++) c[i][j] += a[i][k]*b[k][j];
        }
}


// ---------------------------------------------------------------------
// mat_mul_ijk_trans_vec
// ---------------------------------------------------------------------
// perform matrix multiplication
static void mat_mul_ijk_trans_vec(T** a, T** b, T** c, unsigned n) {

    long i, j, k;

    _mat_transpose(b, n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            VEC sump = { 0 };
            for (k = 0; k < n-STEP+1; k+=STEP) {
                VEC ap = LOAD((VEC*)&a[i][k]);
                VEC bp = LOAD((VEC*)&b[j][k]);
                sump = ADD(sump, MUL(ap,bp));
            }
            T sum = 0;
            for (; k<n; k++) sum += a[i][k]*b[j][k];
            c[i][j] = sum;
            for (k=0; k<STEP; k++) c[i][j] += ((T*)&sump)[k];
        }

    _mat_transpose(b, n);
}


// ---------------------------------------------------------------------
// mat_mul_ikj_vec_pthread
// ---------------------------------------------------------------------
// perform matrix multiplication

typedef struct {
    T **a, **b, **c;
    unsigned n;
    long from, to;
} _data_pack;

static void* _pthread_func(void* p) {

    // unpack parameters
    _data_pack* d = (_data_pack*)p;
    T **a = d->a, **b = d->b, **c = d->c;
    unsigned n = d->n;

    long i, j, k;

    for (i = d->from; i < d->to; i++)
        for (j = 0; j < n; j++) c[i][j] = 0;

    for (i = d->from; i < d->to; i++)
        for (k = 0; k < n; k++) {
            T aik = a[i][k];
            #if VERSION == AVX2
            VEC ap = SET(aik,aik,aik,aik,aik,aik,aik,aik);
            #else
            VEC ap = SET(aik,aik,aik,aik);
            #endif
            for (j = 0; j < n-STEP+1; j+=STEP) {
                VEC bp = LOAD((VEC*)&b[k][j]);
                VEC cp = LOAD((VEC*)&c[i][j]);
                cp = ADD(cp, MUL(ap,bp));
                STORE((VEC*)&c[i][j], cp);
            }
            for (; j<n; j++) c[i][j] += a[i][k]*b[k][j];
        }

    return NULL;
}

void mat_mul_ikj_vec_2thread(T** a, T** b, T** c, unsigned n) {
    pthread_t t1, t2;
    int res1, res2;
    _data_pack dp1 = { a, b, c, n, 0, n/2   };
    _data_pack dp2 = { a, b, c, n, n/2, n };
    res1 = pthread_create(&t1, NULL, _pthread_func, (void*)&dp1);
    res2 = pthread_create(&t2, NULL, _pthread_func, (void*)&dp2);
    assert(res1 == 0);
    assert(res2 == 0);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL); 
}

void mat_mul_ikj_vec_4thread(T** a, T** b, T** c, unsigned n) {
    pthread_t t1, t2, t3, t4;
    int res1, res2, res3, res4;
    _data_pack dp1 = { a, b, c, n, 0, n/4     };
    _data_pack dp2 = { a, b, c, n, n/4, n/2   };
    _data_pack dp3 = { a, b, c, n, n/2, 3*n/4 };
    _data_pack dp4 = { a, b, c, n, 3*n/4, n   };
    res1 = pthread_create(&t1, NULL, _pthread_func, (void*)&dp1);
    res2 = pthread_create(&t2, NULL, _pthread_func, (void*)&dp2);
    res3 = pthread_create(&t3, NULL, _pthread_func, (void*)&dp3);
    res4 = pthread_create(&t4, NULL, _pthread_func, (void*)&dp4);
    assert(res1 == 0);
    assert(res2 == 0);
    assert(res3 == 0);
    assert(res4 == 0);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL);
    pthread_join(t4, NULL); 
}

/* Copyright (C) 2013-2015 Camil Demetrescu

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
*/
