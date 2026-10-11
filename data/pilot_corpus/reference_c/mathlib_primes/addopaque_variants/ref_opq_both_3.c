#include <stdio.h>
static volatile int opq_38ae = 7;
static volatile int opq_38ae_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    if ((((opq_38ae * opq_38ae) % 4) == 2)) {
        { int jv_9da42 = opq_38ae ^ 0x4F43;
            jv_9da42 ^= (jv_9da42 << 3) | 0x72C7;
            jv_9da42 += (jv_9da42 >> 2) + 0xF9;
            jv_9da42 = (jv_9da42 * 0x25) % 0x7FFFFFFF;
          (void)jv_9da42; }
    }
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    int count = 0, last = 0;
    if ((((opq_38ae * opq_38ae + opq_38ae_b * opq_38ae_b) % 4) == 3)) {
        { int jv_2f14d = opq_38ae ^ 0x553F;
            jv_2f14d = (jv_2f14d * 0x2B) % 0x7FFFFFFF;
            jv_2f14d ^= (jv_2f14d << 3) | 0xC089;
          (void)jv_2f14d; }
    }
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if ((((opq_38ae * (opq_38ae + 1)) % 2) == 0)) { opq_38ae_b ^= 0; }
    return 0;
}
