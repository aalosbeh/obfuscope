#include <stdio.h>
static volatile int opq_7e2d = 7;
static volatile int opq_7e2d_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    if ((((opq_7e2d * opq_7e2d + opq_7e2d_b * opq_7e2d_b) % 4) == 3)) {
        { int jv_f5849 = opq_7e2d ^ 0x8799;
            jv_f5849 ^= (jv_f5849 << 3) | 0x627F;
          (void)jv_f5849; }
    }
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    if ((((opq_7e2d * opq_7e2d) % 4) == 2)) {
        { int jv_49026 = opq_7e2d ^ 0x999B;
            jv_49026 = (jv_49026 * 0x7) % 0x7FFFFFFF;
          (void)jv_49026; }
    }
    sieve[0] = sieve[1] = 0;
    if ((((opq_7e2d * opq_7e2d) % 4) == 2)) {
        { int jv_c590d = opq_7e2d ^ 0xEC28;
            jv_c590d += (jv_c590d >> 2) + 0x2B;
          (void)jv_c590d; }
    }
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
