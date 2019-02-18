#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "veq32.h"

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
static void do_test(const int* a, int na, const int* b, int nb, int test_no, int print_time) {

    double start, tseq, tsse;
    int i, rseq = 0, rsse = 0;

    printf("\nTest #%d\n", test_no);

    // sequential
    start = get_real_time();
    for (i=0; i<M; ++i) rseq += veq32_seq(a, na, b, nb);
    tseq  = get_real_time()-start;

    // SSE
    start = get_real_time();
    for (i=0; i<M; ++i) rsse += veq32(a, na, b, nb);
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
    int* a = malloc(N*sizeof(int));
    int* b = malloc(N*sizeof(int));
    int* c = malloc(N*sizeof(int));
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    for (i=0; i<N; ++i)
        a[i] = b[i] = c[i] = 33 + i % 94;

    b[N-1] = 32;
    c[N-20] = 32;

    do_test(a, N-1, b, N-1, 1, 1);         // 1
    do_test(a, N, c, N, 2, 1);             // 0
    do_test(a, N/2, b, N, 3, 0);           // 0
    do_test(a, N, b, N, 4, 1);             // 0
    do_test(a, 10, b, 10, 5, 0);           // 1
    do_test(a+N-10, 10, c+N-10, 10, 6, 0); // 1
    do_test(a+N-10, 10, b+N-10, 10, 6, 0); // 0

    free(a);
    free(b);
    free(c);

    return 0;
}
