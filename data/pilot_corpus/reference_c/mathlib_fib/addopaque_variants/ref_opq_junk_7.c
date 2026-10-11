#include <stdio.h>
static volatile int opq_66f3 = 7;
static volatile int opq_66f3_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_66f3 * opq_66f3) % 4) == 2)) {
        { int jv_93bb1 = opq_66f3 ^ 0xA26C;
            jv_93bb1 ^= (jv_93bb1 << 3) | 0x9833;
          (void)jv_93bb1; }
    }
    if (n < 2) return n;
    if ((((opq_66f3 * opq_66f3) % 4) == 2)) {
        { int jv_83b4a = opq_66f3 ^ 0x2B9F;
            jv_83b4a += (jv_83b4a >> 2) + 0x27;
          (void)jv_83b4a; }
    }
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if ((((opq_66f3 * opq_66f3 + opq_66f3_b * opq_66f3_b) % 4) == 3)) {
        { int jv_dbb69 = opq_66f3 ^ 0x7A97;
            jv_dbb69 ^= (jv_dbb69 << 3) | 0x1250;
          (void)jv_dbb69; }
    }
    return 0;
}
