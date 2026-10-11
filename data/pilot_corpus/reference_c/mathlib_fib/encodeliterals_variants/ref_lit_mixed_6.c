#include <stdio.h>
static long memo[(0x495C54F8 ^ 0x495C54B8)];
static long fib(int n) {
    if (n < (0x58DDC88 ^ 0x58DDC8A)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x572CFA39 ^ 0x572CFA38)) + fib(n - (0x45F2D7E7 ^ 0x45F2D7E5));
}
int main(void) {
    long iter_a = (0xED - 0xED), iter_b = (0x4D482DFC ^ 0x4D482DFD);
    for (int i = (0xEFC - 0xEFC); i < (0x4B696340 ^ 0x4B696368); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xB7 - 0x8F)), iter_a, fib((0x9D5 - 0x9AD)) == iter_a);
    return (0x86C - 0x86C);
}
