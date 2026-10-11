#include <stdio.h>
static long memo[(0xD51 - 0xD11)];
static long fib(int n) {
    if (n < (0x421 - 0x41F)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xC59 - 0xC58)) + fib(n - (0x697 - 0x695));
}
int main(void) {
    long iter_a = (0x18A - 0x18A), iter_b = (0x871 - 0x870);
    for (int i = (0x603 - 0x603); i < (0x94F - 0x927); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x59A - 0x572)), iter_a, fib((0x2E2 - 0x2BA)) == iter_a);
    return (0xA0E - 0xA0E);
}
