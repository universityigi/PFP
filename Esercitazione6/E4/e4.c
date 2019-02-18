#include "e4.h"
#include <emmintrin.h>

// ---------------------------------------------------------------------
// count_occ
// ---------------------------------------------------------------------
// SSE version

int count_occ(const char* v, int n, char x) {
    // to be completed...
    char buf[16];
    int j;
    __m128i xx=_mm_set1_epi8(x);
    __m128i cntx=_mm_setzero_si128();
    int i,cnt=0;
    for (i=0; i+15<n; i+=16){
		__m128i vx=_mm_loadu_si128((const __m128i *)(v+i));
		__m128i ris=_mm_cmpeq_epi8(vx,xx);
		cntx=_mm_add_epi8(ris,cntx);
		if(i%2048==0){
			_mm_storeu_si128((__m128i*)buf,cntx);
			for (j=0; j<16; j++){
				cnt-=buf[j];
			}
			cntx=_mm_setzero_si128();
		}
		
		
	}
	for (;i<n; i++){
		cnt+=v[i]==x;
	}
	_mm_storeu_si128((__m128i*)buf,cntx);
	for (j=0; j<16; j++){
		cnt-=buf[j];
	}
    return cnt;
}


// ---------------------------------------------------------------------
// count_occ_seq
// ---------------------------------------------------------------------
// sequential version

int count_occ_seq(const char* v, int n, char x) {
    int i, cnt = 0;
    for (i=0; i<n; ++i) cnt += v[i] == x;
    return cnt;
}
