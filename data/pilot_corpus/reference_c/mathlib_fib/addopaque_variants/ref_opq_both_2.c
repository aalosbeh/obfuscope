#include <stdio.h>
static volatile int opq_f0ce = 7;
static volatile int opq_f0ce_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_f0ce * opq_f0ce) % 4) == 2)) {
        { int jv_30f2c = opq_f0ce ^ 0x8D98;
            jv_30f2c = (jv_30f2c * 0xA) % 0x7FFFFFFF;
          (void)jv_30f2c; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    if ((((opq_f0ce * opq_f0ce + opq_f0ce) % 2) == 0)) { opq_f0ce_b ^= 0; }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    if ((((opq_f0ce * (opq_f0ce + 1)) % 2) == 0)) { opq_f0ce_b ^= 0; }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
