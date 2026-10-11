#include <stdio.h>
static long memo[(0x55D - 0x51D)];
static long fib(int n) {
    if (n < (0xA66 - 0xA64)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xFD0 - 0xFCF)) + fib(n - (0x316 - 0x314));
}
int main(void) {
    long iter_a = (0xBD4 - 0xBD4), iter_b = (0x5C9 - 0x5C8);
    for (int i = (0x271 - 0x271); i < (0x245 - 0x21D); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x595 - 0x56D)), iter_a, fib((0x5B1 - 0x589)) == iter_a);
    return (0x455 - 0x455);
}
