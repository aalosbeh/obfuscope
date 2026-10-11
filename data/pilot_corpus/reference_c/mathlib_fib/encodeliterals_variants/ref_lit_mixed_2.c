#include <stdio.h>
static long memo[(0x89E - 0x85E)];
static long fib(int n) {
    if (n < (0x437 - 0x435)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x243 - 0x242)) + fib(n - (0x373646E0 ^ 0x373646E2));
}
int main(void) {
    long iter_a = (0x3C8 - 0x3C8), iter_b = (0x5BF - 0x5BE);
    for (int i = (0x49B - 0x49B); i < (0x19253DD7 ^ 0x19253DFF); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x3F8CB122 ^ 0x3F8CB10A)), iter_a, fib((0x5894AF1A ^ 0x5894AF32)) == iter_a);
    return (0x9F5 - 0x9F5);
}
