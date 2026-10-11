#include <stdio.h>
static volatile int opq_2745 = 7;
static volatile int opq_2745_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_2745 * opq_2745 + opq_2745) % 2) == 0)) { opq_2745_b ^= 0; }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    if (((opq_2745 * opq_2745 - opq_2745) % 2 == 0)) { opq_2745_b ^= 0; }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if (((opq_2745 * opq_2745 - opq_2745) % 2 == 0)) { opq_2745_b ^= 0; }
    return 0;
}
