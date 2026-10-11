#include <stdio.h>
static volatile int opq_bcf2 = 7;
static volatile int opq_bcf2_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_bcf2 * opq_bcf2) % 4) == 2)) {
        { int jv_2653a = opq_bcf2 ^ 0xD1BA;
            jv_2653a += (jv_2653a >> 2) + 0x28;
            jv_2653a ^= (jv_2653a << 3) | 0xDAC1;
            jv_2653a = (jv_2653a * 0x1F) % 0x7FFFFFFF;
          (void)jv_2653a; }
    }
    char sieve[LIM];
    if ((((opq_bcf2 * opq_bcf2 + opq_bcf2_b * opq_bcf2_b) % 4) == 3)) {
        { int jv_4a64d = opq_bcf2 ^ 0x37ED;
            jv_4a64d += (jv_4a64d >> 2) + 0xC4;
          (void)jv_4a64d; }
    }
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_bcf2 * opq_bcf2 + opq_bcf2_b * opq_bcf2_b) % 4) == 3)) {
        { int jv_2cdde = opq_bcf2 ^ 0x2707;
            jv_2cdde ^= (jv_2cdde << 3) | 0xBD11;
            jv_2cdde += (jv_2cdde >> 2) + 0x5D;
            jv_2cdde = (jv_2cdde * 0x1B) % 0x7FFFFFFF;
          (void)jv_2cdde; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
