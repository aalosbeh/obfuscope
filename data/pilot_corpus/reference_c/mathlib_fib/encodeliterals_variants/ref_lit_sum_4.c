#include <stdio.h>
static long memo[(0x639 - 0x5F9)];
static long fib(int n) {
    if (n < (0x544 - 0x542)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xB87 - 0xB86)) + fib(n - (0x2D3 - 0x2D1));
}
int main(void) {
    long iter_a = (0x5E8 - 0x5E8), iter_b = (0x6F0 - 0x6EF);
    for (int i = (0x7C1 - 0x7C1); i < (0x4F3 - 0x4CB); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x1FB - 0x1D3)), iter_a, fib((0x648 - 0x620)) == iter_a);
    return (0xDEB - 0xDEB);
}
