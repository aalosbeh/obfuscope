#include <stdio.h>
static volatile int opq_6722 = 7;
static volatile int opq_6722_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_6722 * opq_6722) % 4) == 2)) {
        { int jv_3fc2e = opq_6722 ^ 0x22F5;
            jv_3fc2e += (jv_3fc2e >> 2) + 0xF6;
            jv_3fc2e ^= (jv_3fc2e << 3) | 0xCA17;
          (void)jv_3fc2e; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_6722 * opq_6722) % 4) == 2)) {
        { int jv_2f5e4 = opq_6722 ^ 0xE4F5;
            jv_2f5e4 ^= (jv_2f5e4 << 3) | 0xE121;
            jv_2f5e4 += (jv_2f5e4 >> 2) + 0xF2;
          (void)jv_2f5e4; }
    }
    long iter_a = 0, iter_b = 1;
    if ((((opq_6722 * opq_6722 + opq_6722_b * opq_6722_b) % 4) == 3)) {
        { int jv_baf53 = opq_6722 ^ 0x3137;
            jv_baf53 ^= (jv_baf53 << 3) | 0xB84C;
            jv_baf53 = (jv_baf53 * 0x12) % 0x7FFFFFFF;
            jv_baf53 += (jv_baf53 >> 2) + 0xA1;
          (void)jv_baf53; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
