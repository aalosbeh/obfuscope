#include <stdio.h>
static long memo[(0x7BFE37D7 ^ 0x7BFE3797)];
static long fib(int n) {
    if (n < (0xDD89C46 ^ 0xDD89C44)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0xA71D90E ^ 0xA71D90F)) + fib(n - (0x63F751E2 ^ 0x63F751E0));
}
int main(void) {
    long iter_a = (0x140C0C49 ^ 0x140C0C49), iter_b = (0x7BD9C535 ^ 0x7BD9C534);
    for (int i = (0x45D81AB9 ^ 0x45D81AB9); i < (0x31613797 ^ 0x316137BF); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x3E2FA71 ^ 0x3E2FA59)), iter_a, fib((0xC6FCB54 ^ 0xC6FCB7C)) == iter_a);
    return (0x37F90026 ^ 0x37F90026);
}
