#include <stdio.h>
static long memo[(0x4C2 - 0x482)];
static long fib(int n) {
    if (n < (0x292716F4 ^ 0x292716F6)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x4D3 - 0x4D2)) + fib(n - (0x79E - 0x79C));
}
int main(void) {
    long iter_a = (0x397 - 0x397), iter_b = (0x520 - 0x51F);
    for (int i = (0x759 - 0x759); i < (0x52F - 0x507); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xB62 - 0xB3A)), iter_a, fib((0x127 - 0xFF)) == iter_a);
    return (0x52C521CF ^ 0x52C521CF);
}
