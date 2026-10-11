#include <stdio.h>
static volatile int opq_b418 = 7;
static volatile int opq_b418_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_b418 * opq_b418 + opq_b418_b * opq_b418_b) % 4) == 3)) {
        { int jv_d334e = opq_b418 ^ 0x5598;
            jv_d334e = (jv_d334e * 0x34) % 0x7FFFFFFF;
            jv_d334e ^= (jv_d334e << 3) | 0xB04C;
            jv_d334e += (jv_d334e >> 2) + 0x31;
          (void)jv_d334e; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    if ((((opq_b418 * opq_b418 + opq_b418_b * opq_b418_b) % 4) == 3)) {
        { int jv_6175c = opq_b418 ^ 0x6248;
            jv_6175c ^= (jv_6175c << 3) | 0x149;
            jv_6175c += (jv_6175c >> 2) + 0x21;
          (void)jv_6175c; }
    }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    if ((((opq_b418 * opq_b418) % 4) == 2)) {
        { int jv_fa110 = opq_b418 ^ 0x940B;
            jv_fa110 = (jv_fa110 * 0x18) % 0x7FFFFFFF;
          (void)jv_fa110; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
