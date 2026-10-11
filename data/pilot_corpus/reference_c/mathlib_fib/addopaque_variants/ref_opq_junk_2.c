#include <stdio.h>
static volatile int opq_ac07 = 7;
static volatile int opq_ac07_b = 3;

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    if ((((opq_ac07 * opq_ac07) % 4) == 2)) {
        { int jv_62878 = opq_ac07 ^ 0x8731;
            jv_62878 = (jv_62878 * 0x12) % 0x7FFFFFFF;
            jv_62878 ^= (jv_62878 << 3) | 0xB6E8;
            jv_62878 += (jv_62878 >> 2) + 0xB7;
          (void)jv_62878; }
    }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_ac07 * opq_ac07) % 4) == 2)) {
        { int jv_9d50d = opq_ac07 ^ 0x6C58;
            jv_9d50d = (jv_9d50d * 0xE) % 0x7FFFFFFF;
          (void)jv_9d50d; }
    }
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    if ((((opq_ac07 * opq_ac07) % 4) == 2)) {
        { int jv_c4c9a = opq_ac07 ^ 0x5D4C;
            jv_c4c9a = (jv_c4c9a * 0x33) % 0x7FFFFFFF;
            jv_c4c9a ^= (jv_c4c9a << 3) | 0x1455;
            jv_c4c9a += (jv_c4c9a >> 2) + 0x87;
          (void)jv_c4c9a; }
    }
    return 0;
}
