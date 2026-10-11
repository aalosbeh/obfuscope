#include <stdio.h>
static volatile int opq_3eaf = 7;
static volatile int opq_3eaf_b = 3;

static long memo[64];
static long fib(int n) {
    if ((((opq_3eaf * opq_3eaf) % 4) == 2)) {
        { int jv_33b0f = opq_3eaf ^ 0x7B21;
            jv_33b0f += (jv_33b0f >> 2) + 0xB8;
          (void)jv_33b0f; }
    }
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    if ((((opq_3eaf * opq_3eaf + opq_3eaf) % 2) == 0)) { opq_3eaf_b ^= 0; }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    if ((((opq_3eaf * opq_3eaf) % 4) == 2)) {
        { int jv_15244 = opq_3eaf ^ 0x4296;
            jv_15244 ^= (jv_15244 << 3) | 0xF44A;
            jv_15244 = (jv_15244 * 0x38) % 0x7FFFFFFF;
            jv_15244 += (jv_15244 >> 2) + 0xD9;
          (void)jv_15244; }
    }
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
