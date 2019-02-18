#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "vpal32.h"

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
static void do_test(const int* v, int n, int test_no, int print_time) {

    double start, tseq, tsse;
    int i, rseq = 0, rsse = 0;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    for (i=0; i<M; ++i) rseq += vpal32_seq(v, n);
    tseq  = get_real_time()-start;

    // SSE
    start = get_real_time();
    for (i=0; i<M; ++i) rsse += vpal32(v, n);
    tsse  = get_real_time()-start;

    printf("- result: %d [expected: %d]\n", rsse, rseq);
    if (print_time) {
        printf("- sequential version: %.2f msec\n", tseq*1000);
        printf("- SSE version: %.2f msec\n", tsse*1000);
        printf("- speedup: %.2fx\n", tseq/(tsse==0.0 ? 1E-9 : tsse));
    }
}


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int main(int argc, char** argv) {

    int i;
    int* a = calloc(N, sizeof(int));
    int* b = calloc(N, sizeof(int));
    int* c = calloc(N, sizeof(int));
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    for (i=0; i<N/2; ++i) {
        a[i] = b[i] = c[i] = 33 + i % 94;
        a[N-1-i] = b[N-1-i] = c[N-1-i] = a[i];
    }

    b[10] = 32;
    c[N/2] = c[N/2+1] = 32;

    do_test(a, N, 1, 1);        // 1
    do_test(b, N, 2, 0);        // 0
    do_test(c, N, 3, 1);        // 0
    do_test(a+10, N-20, 4, 1);  // 1

    free(a);
    free(b);
    free(c);

    return 0;
}
