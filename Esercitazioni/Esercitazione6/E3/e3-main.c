// =====================================================================
//  e3-main.c
// =====================================================================

//  Author:         (c) 2018 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Dec 8, 2018

//  Last changed:   $Date: 2018/12/08 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "e3.h"

#define N1 1001
#define M1 1
#define N2 16
#define M2 100000


// ---------------------------------------------------------------------
// get_real_time
// ---------------------------------------------------------------------
double get_real_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// mat_sum
// ---------------------------------------------------------------------
static long mat_sum(const short** m, int n) {
    int i, j;
    long sum = 0;
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j) sum += m[i][j];        
    return sum;
}


// ---------------------------------------------------------------------
// do_test
// ---------------------------------------------------------------------
static int do_test(const short** a, const short** b, short** c, 
                    int n, int m, int test_no) {

    double start, tseq, tsse;
    int i;
    long rseq, rsse;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    for (i=0; i<m; ++i) matmul_seq(a, b, c, n);
    tseq  = get_real_time()-start;
    rseq = mat_sum((const short**)c, n);

    // SSE
    start = get_real_time();
    for (i=0; i<m; ++i) matmul(a, b, c, n);
    tsse  = get_real_time()-start;
    rsse = mat_sum((const short**)c, n);

    printf("- result: %ld [expected: %ld]\n", rsse, rseq);
    printf("- sequential version: %.2f msec\n", tseq*1000);
    printf("- SSE version: %.2f msec\n", tsse*1000);
    printf("- speedup: %.2fx\n", tseq/(tsse==0.0 ? 1E-9 : tsse));

    return rsse == rseq;
}


// ---------------------------------------------------------------------
// alloc_mat
// ---------------------------------------------------------------------
static short** alloc_mat(int n) {
    int i;
    short** m = malloc(n*sizeof(short*));
    assert(m != NULL);
    for (i=0; i<n; ++i) {
        m[i] = malloc(n*sizeof(short));
        assert(m[i] != NULL);
    }
    return m;
}


// ---------------------------------------------------------------------
// free_mat
// ---------------------------------------------------------------------
static void free_mat(short** m, int n) {
    int i;
    for (i=0; i<n; ++i) free(m[i]);
    free(m);
}


// ---------------------------------------------------------------------
// init_mat
// ---------------------------------------------------------------------
static void init_mat(short** m, int n, int max) {
    int i, j;
    for (i=0; i<n; ++i) 
        for (j=0; j<n; ++j) m[i][j] = 1 + (i+j) % max; 
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main() {

    int points = 0;

    short** a1 = alloc_mat(N1);
    short** b1 = alloc_mat(N1);
    short** c1 = alloc_mat(N1);
    short** a2 = alloc_mat(N2);
    short** b2 = alloc_mat(N2);
    short** c2 = alloc_mat(N2);

    init_mat(a1, N1, 5);
    init_mat(b1, N1, 3);
    init_mat(a2, N2, 7);
    init_mat(b2, N2, 5);

    points += do_test((const short**)a1, (const short**)b1, c1, N1, M1, 1);
    points += do_test((const short**)a2, (const short**)b2, c2, N2, M2, 2);

    free_mat(a1, N1);
    free_mat(b1, N1);
    free_mat(c1, N1);
    free_mat(a2, N2);
    free_mat(b2, N2);
    free_mat(c2, N2);

    printf("\nPoints: %d out of 2\n", points);

    return 0;
}


// Copyright (C) 2018 Camil Demetrescu

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
// USA
