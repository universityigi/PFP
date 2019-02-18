#include "vpal32.h"
#include <emmintrin.h>
#include <immintrin.h>

// ---------------------------------------------------------------------
// vpal32
// ---------------------------------------------------------------------
// SSE version

int vpal32(const int* v, int n) {
	int i;
	for (i=0; i+3<n; i+=4){
		__m128i va=_mm_loadu_si128((const __m128i *)(v+i));
		__m128i vb=_mm_loadu_si128((const __m128i *)(v+n-4-i));
		__m128i contrario= _mm_shuffle_epi32(vb, _MM_SHUFFLE(0,1,2,3));
		__m128i ris=_mm_cmpeq_epi32(va,contrario);
		if(!_mm_test_all_ones(ris)) return 0;
	}
	for (; i+3<n; i++){
		if(v[i]!=v[n-1-i]) return 0;
	}
    return 1;
}

 
// ---------------------------------------------------------------------
// vpal32_seq
// ---------------------------------------------------------------------
// sequential version

int vpal32_seq(const int* v, int n) {
    int i;
    for (i=0; i<n/2; ++i)
        if (v[i] != v[n-1-i]) return 0;
    return 1;
}
