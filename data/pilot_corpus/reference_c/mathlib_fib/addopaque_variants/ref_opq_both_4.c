#include <stdio.h>
static volatile int opq_3e6e = 7;
static volatile int opq_3e6e_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_3e6e * opq_3e6e) % 4) == 2)) {
        { int jv_5ef8c = opq_3e6e ^ 0xFD43;
            jv_5ef8c = (jv_5ef8c * 0x33) % 0x7FFFFFFF;
          (void)jv_5ef8c; }
    }
    if (n < 2) return n;
    if ((((opq_3e6e * opq_3e6e + opq_3e6e_b * opq_3e6e_b) % 4) == 3)) {
        { int jv_70b29 = opq_3e6e ^ 0xB0F4;
            jv_70b29 += (jv_70b29 >> 2) + 0x46;
          (void)jv_70b29; }
    }
    if (memo[n]) return memo[n];
    if ((((opq_3e6e * opq_3e6e + opq_3e6e_b * opq_3e6e_b) % 4) == 3)) {
        { int jv_fabf5 = opq_3e6e ^ 0x4B8A;
            jv_fabf5 ^= (jv_fabf5 << 3) | 0x3DD4;
            jv_fabf5 = (jv_fabf5 * 0x26) % 0x7FFFFFFF;
          (void)jv_fabf5; }
    }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
