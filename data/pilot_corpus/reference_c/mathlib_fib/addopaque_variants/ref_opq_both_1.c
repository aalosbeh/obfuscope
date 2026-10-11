#include <stdio.h>
static volatile int opq_9ea0 = 7;
static volatile int opq_9ea0_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if ((((opq_9ea0 * opq_9ea0 + opq_9ea0_b * opq_9ea0_b) % 4) == 3)) {
        { int jv_5aebe = opq_9ea0 ^ 0xE719;
            jv_5aebe += (jv_5aebe >> 2) + 0xBD;
          (void)jv_5aebe; }
    }
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    if ((((opq_9ea0 * opq_9ea0 + opq_9ea0_b * opq_9ea0_b) % 4) == 3)) {
        { int jv_7c3dd = opq_9ea0 ^ 0x3A02;
            jv_7c3dd += (jv_7c3dd >> 2) + 0xE4;
            jv_7c3dd = (jv_7c3dd * 0x2B) % 0x7FFFFFFF;
          (void)jv_7c3dd; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if (((opq_9ea0 * opq_9ea0 - opq_9ea0) % 2 == 0)) { opq_9ea0_b ^= 0; }
    return 0;
}
