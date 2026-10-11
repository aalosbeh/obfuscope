#include <stdio.h>
static volatile int opq_1446 = 7;
static volatile int opq_1446_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_1446 * opq_1446) % 4) == 2)) {
        { int jv_7d652 = opq_1446 ^ 0x8D00;
            jv_7d652 ^= (jv_7d652 << 3) | 0xA280;
          (void)jv_7d652; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_1446 * opq_1446 + opq_1446_b * opq_1446_b) % 4) == 3)) {
        { int jv_ed8d5 = opq_1446 ^ 0xBCEB;
            jv_ed8d5 += (jv_ed8d5 >> 2) + 0xA6;
          (void)jv_ed8d5; }
    }
    long iter_a = 0, iter_b = 1;
    if ((((opq_1446 * opq_1446 + opq_1446_b * opq_1446_b) % 4) == 3)) {
        { int jv_fe34e = opq_1446 ^ 0xDC07;
            jv_fe34e += (jv_fe34e >> 2) + 0xF2;
            jv_fe34e = (jv_fe34e * 0x7) % 0x7FFFFFFF;
          (void)jv_fe34e; }
    }
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
