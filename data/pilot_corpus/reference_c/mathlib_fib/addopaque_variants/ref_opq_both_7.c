#include <stdio.h>
static volatile int opq_dddf = 7;
static volatile int opq_dddf_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if ((((opq_dddf * opq_dddf) % 4) == 2)) {
        { int jv_ac6d9 = opq_dddf ^ 0x4B13;
            jv_ac6d9 = (jv_ac6d9 * 0x1D) % 0x7FFFFFFF;
          (void)jv_ac6d9; }
    }
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_dddf * opq_dddf + opq_dddf_b * opq_dddf_b) % 4) == 3)) {
        { int jv_17136 = opq_dddf ^ 0xEA5D;
            jv_17136 ^= (jv_17136 << 3) | 0x884F;
            jv_17136 += (jv_17136 >> 2) + 0x18;
            jv_17136 = (jv_17136 * 0x3B) % 0x7FFFFFFF;
          (void)jv_17136; }
    }
    long iter_a = 0, iter_b = 1;
    if ((((opq_dddf * opq_dddf + opq_dddf_b * opq_dddf_b) % 4) == 3)) {
        { int jv_c146c = opq_dddf ^ 0x29A1;
            jv_c146c += (jv_c146c >> 2) + 0x77;
            jv_c146c ^= (jv_c146c << 3) | 0x8F43;
            jv_c146c = (jv_c146c * 0x35) % 0x7FFFFFFF;
          (void)jv_c146c; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
