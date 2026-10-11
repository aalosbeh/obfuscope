#include <stdio.h>
static long memo[(0x2915D155 ^ 0x2915D115)];
static long fib(int n) {
    if (n < (0xEE2BA45 ^ 0xEE2BA47)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x37FD35A5 ^ 0x37FD35A4)) + fib(n - (0x243D29AF ^ 0x243D29AD));
}
int main(void) {
    long iter_a = (0xB2B623D ^ 0xB2B623D), iter_b = (0x32B0A11D ^ 0x32B0A11C);
    for (int i = (0x5FE68E38 ^ 0x5FE68E38); i < (0x1AC - 0x184); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x764D6975 ^ 0x764D695D)), iter_a, fib((0x194 - 0x16C)) == iter_a);
    return (0x3CDE5AC8 ^ 0x3CDE5AC8);
}
