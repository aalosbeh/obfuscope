#include <stdio.h>
static long memo[(0x5D0 - 0x590)];
static long fib(int n) {
    if (n < (0xC3F - 0xC3D)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xFAA - 0xFA9)) + fib(n - (0x2FD - 0x2FB));
}
int main(void) {
    long iter_a = (0xAA9 - 0xAA9), iter_b = (0xDA3 - 0xDA2);
    for (int i = (0x2F7 - 0x2F7); i < (0xDA3 - 0xD7B); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xDA4 - 0xD7C)), iter_a, fib((0x553 - 0x52B)) == iter_a);
    return (0x48F - 0x48F);
}
