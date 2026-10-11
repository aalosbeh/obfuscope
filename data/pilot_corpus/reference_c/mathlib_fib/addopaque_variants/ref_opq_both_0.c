#include <stdio.h>
static volatile int opq_1b00 = 7;
static volatile int opq_1b00_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_1b00 * opq_1b00) % 4) == 2)) {
        { int jv_60cce = opq_1b00 ^ 0xC7B8;
            jv_60cce += (jv_60cce >> 2) + 0x63;
          (void)jv_60cce; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    if (((opq_1b00 * opq_1b00 - opq_1b00) % 2 == 0)) { opq_1b00_b ^= 0; }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if ((((opq_1b00 * (opq_1b00 + 1)) % 2) == 0)) { opq_1b00_b ^= 0; }
    return 0;
}
