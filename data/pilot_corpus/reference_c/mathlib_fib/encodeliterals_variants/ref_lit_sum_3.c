#include <stdio.h>
static long memo[(0x2AE - 0x26E)];
static long fib(int n) {
    if (n < (0x251 - 0x24F)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xE4A - 0xE49)) + fib(n - (0x4D6 - 0x4D4));
}
int main(void) {
    long iter_a = (0xAA3 - 0xAA3), iter_b = (0x625 - 0x624);
    for (int i = (0x94D - 0x94D); i < (0xA9F - 0xA77); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x52A - 0x502)), iter_a, fib((0xE2F - 0xE07)) == iter_a);
    return (0x90D - 0x90D);
}
