#include <stdio.h>
static volatile int opq_ce85 = 7;
static volatile int opq_ce85_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_ce85 * opq_ce85 + opq_ce85_b * opq_ce85_b) % 4) == 3)) {
        { int jv_6aa4c = opq_ce85 ^ 0x41BF;
            jv_6aa4c = (jv_6aa4c * 0x4) % 0x7FFFFFFF;
            jv_6aa4c ^= (jv_6aa4c << 3) | 0x9A28;
          (void)jv_6aa4c; }
    }
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    if ((((opq_ce85 * opq_ce85) % 4) == 2)) {
        { int jv_3740c = opq_ce85 ^ 0xD56B;
            jv_3740c ^= (jv_3740c << 3) | 0x2F22;
            jv_3740c = (jv_3740c * 0x3A) % 0x7FFFFFFF;
            jv_3740c += (jv_3740c >> 2) + 0xB6;
          (void)jv_3740c; }
    }
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_ce85 * opq_ce85) % 4) == 2)) {
        { int jv_3415d = opq_ce85 ^ 0x5DCE;
            jv_3415d += (jv_3415d >> 2) + 0x5D;
            jv_3415d = (jv_3415d * 0x1B) % 0x7FFFFFFF;
            jv_3415d ^= (jv_3415d << 3) | 0xD8FC;
          (void)jv_3415d; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
