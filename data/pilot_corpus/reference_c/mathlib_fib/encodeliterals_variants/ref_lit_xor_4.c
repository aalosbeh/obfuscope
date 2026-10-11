#include <stdio.h>
static long memo[(0x74659FAD ^ 0x74659FED)];
static long fib(int n) {
    if (n < (0x1C5B87A7 ^ 0x1C5B87A5)) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - (0x114A6124 ^ 0x114A6125)) + fib(n - (0x2B5EF036 ^ 0x2B5EF034));
}
int main(void) {
    long iter_a = (0x1CCBC9B8 ^ 0x1CCBC9B8), iter_b = (0x6BD745DA ^ 0x6BD745DB);
    for (int i = (0x6C18C04D ^ 0x6C18C04D); i < (0xF383303 ^ 0xF38332B); i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib((0xF1042B8 ^ 0xF104290)), iter_a, fib((0x1653AE0D ^ 0x1653AE25)) == iter_a);
    return (0x1B40DEA3 ^ 0x1B40DEA3);
}
