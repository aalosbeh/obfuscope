#include <stdio.h>
static volatile int opq_60e2 = 7;
static volatile int opq_60e2_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    if ((((opq_60e2 * opq_60e2) % 4) == 2)) {
        { int jv_60af7 = opq_60e2 ^ 0xBAB1;
            jv_60af7 = (jv_60af7 * 0x3A) % 0x7FFFFFFF;
            jv_60af7 ^= (jv_60af7 << 3) | 0x4175;
            jv_60af7 += (jv_60af7 >> 2) + 0x7E;
          (void)jv_60af7; }
    }
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_60e2 * opq_60e2 + opq_60e2_b * opq_60e2_b) % 4) == 3)) {
        { int jv_a277a = opq_60e2 ^ 0x19AD;
            jv_a277a += (jv_a277a >> 2) + 0xAD;
            jv_a277a = (jv_a277a * 0x36) % 0x7FFFFFFF;
          (void)jv_a277a; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if ((((opq_60e2 * opq_60e2) % 4) == 2)) {
        { int jv_5793d = opq_60e2 ^ 0x5AE7;
            jv_5793d = (jv_5793d * 0x33) % 0x7FFFFFFF;
            jv_5793d += (jv_5793d >> 2) + 0xA7;
          (void)jv_5793d; }
    }
    return 0;
}
