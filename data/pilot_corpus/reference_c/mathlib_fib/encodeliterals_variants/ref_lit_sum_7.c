#include <stdio.h>
static long memo[(0xE61 - 0xE21)];
static long fib(int n) {
    if (n < (0x5E9 - 0x5E7)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xC4A - 0xC49)) + fib(n - (0x10E - 0x10C));
}
int main(void) {
    long iter_a = (0xB88 - 0xB88), iter_b = (0xBD2 - 0xBD1);
    for (int i = (0xF58 - 0xF58); i < (0x5F - 0x37); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xD0F - 0xCE7)), iter_a, fib((0x56C - 0x544)) == iter_a);
    return (0xBF1 - 0xBF1);
}
