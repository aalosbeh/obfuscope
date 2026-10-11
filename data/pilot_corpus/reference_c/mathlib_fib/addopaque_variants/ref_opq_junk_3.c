#include <stdio.h>
static volatile int opq_590f = 7;
static volatile int opq_590f_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_590f * opq_590f + opq_590f_b * opq_590f_b) % 4) == 3)) {
        { int jv_86b5c = opq_590f ^ 0x8747;
            jv_86b5c = (jv_86b5c * 0xF) % 0x7FFFFFFF;
          (void)jv_86b5c; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_590f * opq_590f) % 4) == 2)) {
        { int jv_eefcd = opq_590f ^ 0xFF0B;
            jv_eefcd ^= (jv_eefcd << 3) | 0x961D;
          (void)jv_eefcd; }
    }
    long iter_a = 0, iter_b = 1;
    if ((((opq_590f * opq_590f + opq_590f_b * opq_590f_b) % 4) == 3)) {
        { int jv_83695 = opq_590f ^ 0x575C;
            jv_83695 ^= (jv_83695 << 3) | 0x9DD2;
          (void)jv_83695; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
