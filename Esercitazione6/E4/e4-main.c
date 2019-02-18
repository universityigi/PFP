// =====================================================================
//  e4-main.c
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

#include "e4.h"

#define N    200003
#define M    1000


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
static int do_test(const char* v, int n, char x, int test_no, int print_time) {

    double start, tseq, tsse;
    int i, rseq = 0, rsse = 0;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    for (i=0; i<M; ++i) rseq += count_occ_seq(v, n, x);
    tseq  = get_real_time()-start;

    // SSE
    start = get_real_time();
    for (i=0; i<M; ++i) rsse += count_occ(v, n, x);
    tsse  = get_real_time()-start;

    printf("- result: %d [expected: %d]\n", rsse, rseq);
    if (print_time) {
        printf("- sequential version: %.2f msec\n", tseq*1000);
        printf("- SSE version: %.2f msec\n", tsse*1000);
        printf("- speedup: %.2fx\n", tseq/(tsse==0.0 ? 1E-9 : tsse));
    }

    return rsse == rseq;
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main() {

    int i, points = 0;
    char* a = malloc(N*sizeof(char));
    char* b = malloc(N*sizeof(char));
    assert(a != NULL);
    assert(b != NULL);

    for (i=0; i<N; ++i) {
        a[i] = 'A' + i % ('Z'-'A'+1); // printable chars galore...
        b[i] = 'A';
    }

    points += do_test(a,     N,   ' ', 1, 1);
    points += do_test(a,     100, 'A', 2, 0);
    points += do_test(a,     N,   'A', 3, 1);
    points += do_test(a,     N,   'Z', 4, 1);
    points += do_test(a+N-3, 3,   'I', 5, 0);
    points += do_test(b,     N,   'A', 6, 1);

    free(a);
    free(b);

    printf("\nPoints: %d out of 6\n", points);

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
