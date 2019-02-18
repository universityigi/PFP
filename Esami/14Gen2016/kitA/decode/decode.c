#include "decode.h"
#include <string.h>
#include <immintrin.h>

void decode(const char* key, int m, char* str) {
    int i, 
    n = strlen(str);
    char keybuf[16]={0};
    memcpy(keybuf,key,m);
     __m128i keyx = _mm_loadu_si128((const __m128i*)keybuf);
    for (i=0; i+16<n; i+=m){
    __m128i strx = _mm_loadu_si128((__m128i*)(str+i));
    strx = _mm_sub_epi8(strx,keyx);
    _mm_storeu_si128((__m128i*)(str+i), strx);
    }
    for (; i<n; i++) str[i] -= key[i % m];
}
