#include <stdio.h>
static long v_5878ff[64];
static long fib(int n) {
    if (n < 2) return n;
    if (v_5878ff[n]) return v_5878ff[n];
    return v_5878ff[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long v_7a9e76 = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = v_7a9e76 + iter_b; v_7a9e76 = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), v_7a9e76, fib(40) == v_7a9e76);
    return 0;
}
