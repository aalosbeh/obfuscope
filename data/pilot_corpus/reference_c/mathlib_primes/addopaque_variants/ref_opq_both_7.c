#include <stdio.h>
static volatile int opq_1e2b = 7;
static volatile int opq_1e2b_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_1e2b * opq_1e2b + opq_1e2b_b * opq_1e2b_b) % 4) == 3)) {
        { int jv_58135 = opq_1e2b ^ 0xCC3A;
            jv_58135 += (jv_58135 >> 2) + 0xA2;
            jv_58135 = (jv_58135 * 0x29) % 0x7FFFFFFF;
          (void)jv_58135; }
    }
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_1e2b * (opq_1e2b + 1)) % 2) == 0)) { opq_1e2b_b ^= 0; }
    int count = 0, last = 0;
    if ((((opq_1e2b * opq_1e2b) % 4) == 2)) {
        { int jv_983de = opq_1e2b ^ 0xAFDF;
            jv_983de = (jv_983de * 0x3D) % 0x7FFFFFFF;
            jv_983de ^= (jv_983de << 3) | 0x13D0;
          (void)jv_983de; }
    }
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
