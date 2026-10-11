#include <stdio.h>
static long memo[(0x6CC05E05 ^ 0x6CC05E45)];
static long fib(int n) {
    if (n < (0x4EEF2FA4 ^ 0x4EEF2FA6)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x6A9A09E7 ^ 0x6A9A09E6)) + fib(n - (0x20211B09 ^ 0x20211B0B));
}
int main(void) {
    long iter_a = (0x2B310178 ^ 0x2B310178), iter_b = (0x24EAEC04 ^ 0x24EAEC05);
    for (int i = (0x5F5505C9 ^ 0x5F5505C9); i < (0x2BBA5F19 ^ 0x2BBA5F31); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x7C3FD9E7 ^ 0x7C3FD9CF)), iter_a, fib((0x74D66DD9 ^ 0x74D66DF1)) == iter_a);
    return (0x280ABAB1 ^ 0x280ABAB1);
}
