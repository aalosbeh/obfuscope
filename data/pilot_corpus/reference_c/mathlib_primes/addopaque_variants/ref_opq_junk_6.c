#include <stdio.h>
static volatile int opq_ad4f = 7;
static volatile int opq_ad4f_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    if ((((opq_ad4f * opq_ad4f) % 4) == 2)) {
        { int jv_6ada4 = opq_ad4f ^ 0x4CD2;
            jv_6ada4 = (jv_6ada4 * 0x3A) % 0x7FFFFFFF;
            jv_6ada4 += (jv_6ada4 >> 2) + 0xCA;
            jv_6ada4 ^= (jv_6ada4 << 3) | 0xF438;
          (void)jv_6ada4; }
    }
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    if ((((opq_ad4f * opq_ad4f) % 4) == 2)) {
        { int jv_ddb90 = opq_ad4f ^ 0x1031;
            jv_ddb90 += (jv_ddb90 >> 2) + 0x8D;
          (void)jv_ddb90; }
    }
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if ((((opq_ad4f * opq_ad4f + opq_ad4f_b * opq_ad4f_b) % 4) == 3)) {
        { int jv_731d7 = opq_ad4f ^ 0x37BF;
            jv_731d7 = (jv_731d7 * 0x31) % 0x7FFFFFFF;
            jv_731d7 += (jv_731d7 >> 2) + 0xAB;
          (void)jv_731d7; }
    }
    return 0;
}
