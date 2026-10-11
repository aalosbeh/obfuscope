#include <stdio.h>
static long v_3eadb4[64];
static long fib(int n) {
    if (n < 2) return n;
    if (v_3eadb4[n]) return v_3eadb4[n];
    return v_3eadb4[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long v_e0e0f5 = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = v_e0e0f5 + iter_b; v_e0e0f5 = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), v_e0e0f5, fib(40) == v_e0e0f5);
    return 0;
}
