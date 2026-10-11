#include <stdio.h>
static long memo[(0x3547BD64 ^ 0x3547BD24)];
static long fib(int n) {
    if (n < (0x56542F0A ^ 0x56542F08)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x259E988F ^ 0x259E988E)) + fib(n - (0xDCB - 0xDC9));
}
int main(void) {
    long iter_a = (0x233882F6 ^ 0x233882F6), iter_b = (0x533 - 0x532);
    for (int i = (0x1BA - 0x1BA); i < (0x2F7DCC15 ^ 0x2F7DCC3D); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x755 - 0x72D)), iter_a, fib((0x485 - 0x45D)) == iter_a);
    return (0x3F5DB883 ^ 0x3F5DB883);
}
