#include <stdio.h>
static long memo[(0x196BE306 ^ 0x196BE346)];
static long fib(int n) {
    if (n < (0x4CE61D6A ^ 0x4CE61D68)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x2AB922C1 ^ 0x2AB922C0)) + fib(n - (0x6D12F919 ^ 0x6D12F91B));
}
int main(void) {
    long iter_a = (0x77EB1A5E ^ 0x77EB1A5E), iter_b = (0x7450315E ^ 0x7450315F);
    for (int i = (0x5485ACC1 ^ 0x5485ACC1); i < (0x2EF0AE59 ^ 0x2EF0AE71); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0x480E777F ^ 0x480E7757)), iter_a, fib((0x50931B51 ^ 0x50931B79)) == iter_a);
    return (0x76F1E6EE ^ 0x76F1E6EE);
}
