#include <stdio.h>
static long memo[(0x31887A53 ^ 0x31887A13)];
static long fib(int n) {
    if (n < (0x175D7549 ^ 0x175D754B)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x2FDB6577 ^ 0x2FDB6576)) + fib(n - (0x4D2F8391 ^ 0x4D2F8393));
}
int main(void) {
    long iter_a = (0xD981472 ^ 0xD981472), iter_b = (0x54F3B7DB ^ 0x54F3B7DA);
    for (int i = (0x698634AC ^ 0x698634AC); i < (0x9EBCADE ^ 0x9EBCAF6); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x526C4058 ^ 0x526C4070)), iter_a, fib((0x257DFE50 ^ 0x257DFE78)) == iter_a);
    return (0x69F38856 ^ 0x69F38856);
}
