#include "e3.h"
#include <emmintrin.h>
#include <smmintrin.h>

// ---------------------------------------------------------------------
// check_rows
// ---------------------------------------------------------------------
// SSE/AVX version

int check_rows(const char* m, int n) {
    // da completare...
    int i,j,k;
    for (i=0; i<n; i++){
		char summa=0;
		__m128i sumx=_mm_setzero_si128();
		unsigned char sum[16]={0};
		for (j=0; j+15<n;j+=16){
			__m128i mx=_mm_loadu_si128((const __m128i *)(m+i*n+j));
			sumx=_mm_add_epi8(sumx,mx);
			if(j%2048==0){
				_mm_storeu_si128((__m128i*)sum,sumx);
				for (k=0;k<16; k++){
					summa+=sum[k];
				}
				sumx=_mm_setzero_si128();
			}
			
		}
		_mm_storeu_si128((__m128i*)sum,sumx);
		for (k=0; k<16; k++){
			summa+=sum[k];
		}
		for (;j<n; j++){
			summa+=m[j+i*n];
		}
		if(summa!=0) return 0;
	}
	
	
    return 1;    
}


// ---------------------------------------------------------------------
// check_rows_seq
// ---------------------------------------------------------------------
// sequential version

int check_rows_seq(const char* m, int n) {
    int i, j;
    for (i=0; i<n; ++i) {
        char sum = 0;
        for (j=0; j<n; ++j) sum += m[i*n+j];
        if (sum != 0) return 0;
    }
    return 1;
}
