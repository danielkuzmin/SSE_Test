// Quick program to test Intel's SSE stuff
#include <stdio.h>
#include <emmintrin.h>
#include <stdint.h>

// This doubles each element in the array using SSE
void double_array(uint32_t *p, int elems) {
    while (elems >=4) {
        __m128i tmp = _mm_loadu_si128((__m128i *)p);
         tmp = _mm_add_epi32(tmp, tmp);
         _mm_storeu_si128((__m128i *)p, tmp);
         p = p + 4;
         elems = elems - 4;
    }

    for (int i = 0; i < elems; i++) {
        p[i] = p[i] + p[i];
    }
}

int main() {
    uint32_t buf[] = {1,2,3,4,5,6};
    double_array(buf, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d", buf[i]);
    }
    return 0;
}