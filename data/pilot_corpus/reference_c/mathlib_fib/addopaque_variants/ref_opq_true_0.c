#include <stdio.h>
static volatile int opq_a8b9 = 7;
static volatile int opq_a8b9_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if ((((opq_a8b9 * (opq_a8b9 + 1)) % 2) == 0)) { opq_a8b9_b ^= 0; }
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_a8b9 * (opq_a8b9 + 1)) % 2) == 0)) { opq_a8b9_b ^= 0; }
    long iter_a = 0, iter_b = 1;
    if (((opq_a8b9 * opq_a8b9 - opq_a8b9) % 2 == 0)) { opq_a8b9_b ^= 0; }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
