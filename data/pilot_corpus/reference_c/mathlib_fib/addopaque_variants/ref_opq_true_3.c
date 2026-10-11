#include <stdio.h>
static volatile int opq_a5f8 = 7;
static volatile int opq_a5f8_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if ((((opq_a5f8 * opq_a5f8 + opq_a5f8) % 2) == 0)) { opq_a5f8_b ^= 0; }
    if (memo[n]) return memo[n];
    if ((((opq_a5f8 * (opq_a5f8 + 1)) % 2) == 0)) { opq_a5f8_b ^= 0; }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if ((((opq_a5f8 * opq_a5f8 + opq_a5f8) % 2) == 0)) { opq_a5f8_b ^= 0; }
    return 0;
}
