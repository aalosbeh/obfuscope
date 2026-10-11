#include <stdio.h>
static long memo[(0x748D9726 ^ 0x748D9766)];
static long fib(int n) {
    if (n < (0x4CBB2C92 ^ 0x4CBB2C90)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x2109E22F ^ 0x2109E22E)) + fib(n - (0x6E7B710 ^ 0x6E7B712));
}
int main(void) {
    long iter_a = (0x5745DCD8 ^ 0x5745DCD8), iter_b = (0x60BAB98C ^ 0x60BAB98D);
    for (int i = (0xA16FEA3 ^ 0xA16FEA3); i < (0x277B96C0 ^ 0x277B96E8); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x79AD1D6C ^ 0x79AD1D44)), iter_a, fib((0x104A8A80 ^ 0x104A8AA8)) == iter_a);
    return (0xB270CA4 ^ 0xB270CA4);
}
