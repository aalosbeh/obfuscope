#include <stdio.h>
static long memo[(0x4BDFD81D ^ 0x4BDFD85D)];
static long fib(int n) {
    if (n < (0x645F4581 ^ 0x645F4583)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x4E6CC126 ^ 0x4E6CC127)) + fib(n - (0x7D1391E3 ^ 0x7D1391E1));
}
int main(void) {
    long iter_a = (0x791ED371 ^ 0x791ED371), iter_b = (0x4332649F ^ 0x4332649E);
    for (int i = (0x56CDFFE2 ^ 0x56CDFFE2); i < (0x2EF9305B ^ 0x2EF93073); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x1B5CB447 ^ 0x1B5CB46F)), iter_a, fib((0x5780A473 ^ 0x5780A45B)) == iter_a);
    return (0x32E06884 ^ 0x32E06884);
}
