#include <stdio.h>
static long hznpnqktwseevzx[64];
static long fib(int n) {
    if (n < 2) return n;
    if (hznpnqktwseevzx[n]) return hznpnqktwseevzx[n];
    return hznpnqktwseevzx[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long judyekvhrurzkp = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = judyekvhrurzkp + iter_b; judyekvhrurzkp = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), judyekvhrurzkp, fib(40) == judyekvhrurzkp);
    return 0;
}
