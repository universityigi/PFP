// =====================================================================
//  e3-main.c
// =====================================================================

//  Author:         (c) 2018 Camil Demetrescu
//  License:        See the end of this file for license information
//  Created:        Dec 18, 2018

//  Last changed:   $Date: 2018/12/18 --:--:-- $
//  Changed by:     $Author: demetres $
//  Revision:       $Revision: 1.00 $


#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "e3.h"

#define N1 2018
#define N2 2018
#define N3 2048
#define M1 100
#define M2 100
#define M3 80


// ---------------------------------------------------------------------
// get_real_time
// ---------------------------------------------------------------------
double get_real_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec+tv.tv_usec*1E-06;
}


// ---------------------------------------------------------------------
// do_test
// ---------------------------------------------------------------------
static int do_test(const char* v, 
                    int n, int m, int test_no) {

    double start, tseq, tsse;
    int i;
    long rseq = 0, rsse = 0;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    for (i=0; i<m; ++i) rseq += check_rows_seq(v, n);
    tseq  = get_real_time()-start;

    // SSE
    start = get_real_time();
    for (i=0; i<m; ++i) rsse += check_rows(v, n);
    tsse  = get_real_time()-start;

    printf("- result: %ld [expected: %ld]\n", rsse, rseq);
    printf("- sequential version: %.2f msec\n", tseq*1000);
    printf("- SSE version: %.2f msec\n", tsse*1000);
    printf("- speedup: %.2fx\n", tseq/(tsse==0.0 ? 1E-9 : tsse));

    return rsse == rseq;
}


// ---------------------------------------------------------------------
// init_mat
// ---------------------------------------------------------------------
static void init_mat(char* m, int n) {
    int i, j;
    for (i=0; i<n; ++i) 
        for (j=0; j<n; ++j) 
            m[i*n+j] = j < n/2 ? 1 : -1; 
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main() {

    int points = 0;

    char* m1 = malloc(N1*N1*sizeof(char));
    char* m2 = malloc(N2*N2*sizeof(char));
    char* m3 = malloc(N3*N3*sizeof(char));
    assert(m1!=NULL);
    assert(m2!=NULL);
    assert(m3!=NULL);
    init_mat(m1, N2);
    init_mat(m2, N2);
    init_mat(m3, N3);

    points += do_test(m1, N1, M1, 1);
    m1[(N1-1)*N1+N1-1] = 0;
    points += do_test(m1, N1, M1, 2);
    m2[(N2-1)*N2] = 0;
    points += do_test(m2, N2, M2, 3);
    points += do_test(m3, N3, M3, 4);

    free(m1);
    free(m2);

    printf("\nPoints: %d out of 4\n", points);

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
