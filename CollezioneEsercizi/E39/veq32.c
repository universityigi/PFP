#include "veq32.h"
#include <tmmintrin.h>
#include <xmmintrin.h>
#include <smmintrin.h>

// ---------------------------------------------------------------------
// veq32
// ---------------------------------------------------------------------
// versione vettorizzata

int veq32(const int* a, int na, const int* b, int nb) {
    // da completare..
    if(na!=nb) return 0;
    else{
		int i;
		for (i=0; i+3<na; i+=4){
			__m128i ax=_mm_loadu_si128((const __m128i *)(a+i));
			__m128i bx=_mm_loadu_si128((const __m128i *)(b+i));
			__m128i ris=_mm_cmpeq_epi32(ax,bx);
			if(!(_mm_test_all_ones(ris))) return  0;
		}
		for (; i<na; i++){
			if(a[i]!=b[i]) return 0;
		}
		
	}
	return 1;
}


// ---------------------------------------------------------------------
// veq32_seq
// ---------------------------------------------------------------------
// versione sequenziale

int veq32_seq(const int* a, int na, const int* b, int nb) {
    int i;
    if (na != nb) return 0;
    for (i=0; i<na; ++i)
        if (a[i] != b[i]) return 0;
    return 1;
}
