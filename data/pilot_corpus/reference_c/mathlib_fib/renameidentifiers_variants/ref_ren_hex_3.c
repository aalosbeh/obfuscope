#include <stdio.h>
static long v_485fb3[64];
static long fib(int n) {
    if (n < 2) return n;
    if (v_485fb3[n]) return v_485fb3[n];
    return v_485fb3[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long v_48ddf6 = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = v_48ddf6 + iter_b; v_48ddf6 = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), v_48ddf6, fib(40) == v_48ddf6);
    return 0;
}
