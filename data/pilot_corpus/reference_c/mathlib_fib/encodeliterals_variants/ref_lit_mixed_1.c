#include <stdio.h>
static long memo[(0x228 - 0x1E8)];
static long fib(int n) {
    if (n < (0xEB54299 ^ 0xEB5429B)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x2B4 - 0x2B3)) + fib(n - (0x72CFE2DB ^ 0x72CFE2D9));
}
int main(void) {
    long iter_a = (0x6FDD0C0A ^ 0x6FDD0C0A), iter_b = (0x51A - 0x519);
    for (int i = (0x27DC3B2E ^ 0x27DC3B2E); i < (0xFB8BF0E ^ 0xFB8BF26); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x33BAFA70 ^ 0x33BAFA58)), iter_a, fib((0x58482C14 ^ 0x58482C3C)) == iter_a);
    return (0x12E3A734 ^ 0x12E3A734);
}
