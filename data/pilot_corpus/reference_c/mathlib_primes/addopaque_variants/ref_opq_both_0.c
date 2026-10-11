#include <stdio.h>
static volatile int opq_c7e2 = 7;
static volatile int opq_c7e2_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_c7e2 * opq_c7e2) % 4) == 2)) {
        { int jv_75a40 = opq_c7e2 ^ 0x38E2;
            jv_75a40 += (jv_75a40 >> 2) + 0x66;
          (void)jv_75a40; }
    }
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    if ((((opq_c7e2 * opq_c7e2 + opq_c7e2_b * opq_c7e2_b) % 4) == 3)) {
        { int jv_ecfc7 = opq_c7e2 ^ 0xCBC6;
            jv_ecfc7 += (jv_ecfc7 >> 2) + 0x77;
            jv_ecfc7 ^= (jv_ecfc7 << 3) | 0xAE92;
          (void)jv_ecfc7; }
    }
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    int count = 0, last = 0;
    if ((((opq_c7e2 * (opq_c7e2 + 1)) % 2) == 0)) { opq_c7e2_b ^= 0; }
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
