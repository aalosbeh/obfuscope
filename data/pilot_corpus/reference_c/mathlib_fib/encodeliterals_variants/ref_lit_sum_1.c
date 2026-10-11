#include <stdio.h>
static long memo[(0x2C2 - 0x282)];
static long fib(int n) {
    if (n < (0x39B - 0x399)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xC2A - 0xC29)) + fib(n - (0xCC - 0xCA));
}
int main(void) {
    long iter_a = (0xA25 - 0xA25), iter_b = (0xE9 - 0xE8);
    for (int i = (0xB5 - 0xB5); i < (0x547 - 0x51F); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xB4A - 0xB22)), iter_a, fib((0x6AD - 0x685)) == iter_a);
    return (0x574 - 0x574);
}
