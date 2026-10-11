#include <stdio.h>
static long memo[(0x5F - 0x1F)];
static long fib(int n) {
    if (n < (0xD51 - 0xD4F)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xF9F - 0xF9E)) + fib(n - (0x2C7 - 0x2C5));
}
int main(void) {
    long iter_a = (0xC68 - 0xC68), iter_b = (0xA55 - 0xA54);
    for (int i = (0x33E - 0x33E); i < (0x8A7 - 0x87F); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xC98 - 0xC70)), iter_a, fib((0x4EE - 0x4C6)) == iter_a);
    return (0x648 - 0x648);
}
