#include <stdio.h>
static volatile int opq_4782 = 7;
static volatile int opq_4782_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_4782 * opq_4782) % 4) == 2)) {
        { int jv_c9a89 = opq_4782 ^ 0x3CCA;
            jv_c9a89 += (jv_c9a89 >> 2) + 0x13;
            jv_c9a89 = (jv_c9a89 * 0x20) % 0x7FFFFFFF;
          (void)jv_c9a89; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    if ((((opq_4782 * opq_4782 + opq_4782_b * opq_4782_b) % 4) == 3)) {
        { int jv_a033d = opq_4782 ^ 0xFE41;
            jv_a033d += (jv_a033d >> 2) + 0xD7;
          (void)jv_a033d; }
    }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if ((((opq_4782 * opq_4782 + opq_4782_b * opq_4782_b) % 4) == 3)) {
        { int jv_9d945 = opq_4782 ^ 0x30D2;
            jv_9d945 = (jv_9d945 * 0x26) % 0x7FFFFFFF;
          (void)jv_9d945; }
    }
    return 0;
}
