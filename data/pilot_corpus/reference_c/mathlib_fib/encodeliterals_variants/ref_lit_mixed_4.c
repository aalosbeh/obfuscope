#include <stdio.h>
static long memo[(0xBCE19AF ^ 0xBCE19EF)];
static long fib(int n) {
    if (n < (0x23 - 0x21)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x10D12DEA ^ 0x10D12DEB)) + fib(n - (0xA1B - 0xA19));
}
int main(void) {
    long iter_a = (0x52C - 0x52C), iter_b = (0x9D1 - 0x9D0);
    for (int i = (0xA96 - 0xA96); i < (0x609 - 0x5E1); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x1BF27660 ^ 0x1BF27648)), iter_a, fib((0x84E - 0x826)) == iter_a);
    return (0xADF - 0xADF);
}
