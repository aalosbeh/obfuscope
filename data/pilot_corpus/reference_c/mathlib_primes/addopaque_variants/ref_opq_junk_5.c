#include <stdio.h>
static volatile int opq_b811 = 7;
static volatile int opq_b811_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    if ((((opq_b811 * opq_b811 + opq_b811_b * opq_b811_b) % 4) == 3)) {
        { int jv_2eb9e = opq_b811 ^ 0x55E9;
            jv_2eb9e += (jv_2eb9e >> 2) + 0xC2;
            jv_2eb9e ^= (jv_2eb9e << 3) | 0xB06B;
          (void)jv_2eb9e; }
    }
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_b811 * opq_b811 + opq_b811_b * opq_b811_b) % 4) == 3)) {
        { int jv_dbb6d = opq_b811 ^ 0x7892;
            jv_dbb6d ^= (jv_dbb6d << 3) | 0xA98D;
          (void)jv_dbb6d; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if ((((opq_b811 * opq_b811) % 4) == 2)) {
        { int jv_90fdb = opq_b811 ^ 0x84C9;
            jv_90fdb = (jv_90fdb * 0x6) % 0x7FFFFFFF;
          (void)jv_90fdb; }
    }
    return 0;
}
