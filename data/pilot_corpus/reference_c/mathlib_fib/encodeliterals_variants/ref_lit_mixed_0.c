#include <stdio.h>
static long memo[(0x5CD - 0x58D)];
static long fib(int n) {
    if (n < (0x36A - 0x368)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x466 - 0x465)) + fib(n - (0x2E3631AC ^ 0x2E3631AE));
}
int main(void) {
    long iter_a = (0xC02 - 0xC02), iter_b = (0x9F2 - 0x9F1);
    for (int i = (0x4516D522 ^ 0x4516D522); i < (0x4E895740 ^ 0x4E895768); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x355A7A53 ^ 0x355A7A7B)), iter_a, fib((0x8C8 - 0x8A0)) == iter_a);
    return (0x2CC11747 ^ 0x2CC11747);
}
