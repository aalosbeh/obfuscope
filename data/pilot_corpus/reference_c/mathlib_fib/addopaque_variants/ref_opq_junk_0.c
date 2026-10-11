#include <stdio.h>
static volatile int opq_5769 = 7;
static volatile int opq_5769_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if ((((opq_5769 * opq_5769 + opq_5769_b * opq_5769_b) % 4) == 3)) {
        { int jv_8d4b5 = opq_5769 ^ 0x58FF;
            jv_8d4b5 ^= (jv_8d4b5 << 3) | 0xED63;
          (void)jv_8d4b5; }
    }
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_5769 * opq_5769) % 4) == 2)) {
        { int jv_f5a38 = opq_5769 ^ 0x337A;
            jv_f5a38 = (jv_f5a38 * 0x3E) % 0x7FFFFFFF;
            jv_f5a38 ^= (jv_f5a38 << 3) | 0xB6;
            jv_f5a38 += (jv_f5a38 >> 2) + 0x97;
          (void)jv_f5a38; }
    }
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if ((((opq_5769 * opq_5769) % 4) == 2)) {
        { int jv_1a350 = opq_5769 ^ 0x6766;
            jv_1a350 ^= (jv_1a350 << 3) | 0x3A5D;
          (void)jv_1a350; }
    }
    return 0;
}
