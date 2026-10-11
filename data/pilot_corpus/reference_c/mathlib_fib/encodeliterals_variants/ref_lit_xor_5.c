#include <stdio.h>
static long memo[(0x7096F141 ^ 0x7096F101)];
static long fib(int n) {
    if (n < (0xA40C246 ^ 0xA40C244)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x3015177D ^ 0x3015177C)) + fib(n - (0x266D95D7 ^ 0x266D95D5));
}
int main(void) {
    long iter_a = (0x5A7607A9 ^ 0x5A7607A9), iter_b = (0x73B7A228 ^ 0x73B7A229);
    for (int i = (0x18262838 ^ 0x18262838); i < (0x3EF155DC ^ 0x3EF155F4); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x4912C086 ^ 0x4912C0AE)), iter_a, fib((0x60665051 ^ 0x60665079)) == iter_a);
    return (0x30D885EC ^ 0x30D885EC);
}
