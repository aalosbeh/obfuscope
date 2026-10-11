#include <stdio.h>
static volatile int opq_f215 = 7;
static volatile int opq_f215_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if ((((opq_f215 * (opq_f215 + 1)) % 2) == 0)) { opq_f215_b ^= 0; }
    if (memo[n]) return memo[n];
    if ((((opq_f215 * (opq_f215 + 1)) % 2) == 0)) { opq_f215_b ^= 0; }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    if ((((opq_f215 * opq_f215 + opq_f215) % 2) == 0)) { opq_f215_b ^= 0; }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
