#include <stdio.h>
static long v_83e6c9[64];
static long fib(int n) {
    if (n < 2) return n;
    if (v_83e6c9[n]) return v_83e6c9[n];
    return v_83e6c9[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long v_2d0b69 = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = v_2d0b69 + iter_b; v_2d0b69 = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), v_2d0b69, fib(40) == v_2d0b69);
    return 0;
}
