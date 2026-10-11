#include <stdio.h>
static volatile int opq_3433 = 7;
static volatile int opq_3433_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_3433 * opq_3433) % 4) == 2)) {
        { int jv_d7797 = opq_3433 ^ 0xB886;
            jv_d7797 += (jv_d7797 >> 2) + 0x12;
            jv_d7797 ^= (jv_d7797 << 3) | 0x3ED6;
            jv_d7797 = (jv_d7797 * 0x1C) % 0x7FFFFFFF;
          (void)jv_d7797; }
    }
    if (n < 2) return n;
    if ((((opq_3433 * opq_3433) % 4) == 2)) {
        { int jv_b987e = opq_3433 ^ 0x7D8B;
            jv_b987e = (jv_b987e * 0xA) % 0x7FFFFFFF;
            jv_b987e ^= (jv_b987e << 3) | 0xA233;
          (void)jv_b987e; }
    }
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    if ((((opq_3433 * opq_3433) % 4) == 2)) {
        { int jv_2485f = opq_3433 ^ 0x6EB4;
            jv_2485f += (jv_2485f >> 2) + 0x3F;
            jv_2485f ^= (jv_2485f << 3) | 0xAFBD;
            jv_2485f = (jv_2485f * 0x2B) % 0x7FFFFFFF;
          (void)jv_2485f; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
