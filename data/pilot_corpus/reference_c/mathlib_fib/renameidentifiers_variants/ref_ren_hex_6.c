#include <stdio.h>
static long v_671d4c[64];
static long fib(int n) {
    if (n < 2) return n;
    if (v_671d4c[n]) return v_671d4c[n];
    return v_671d4c[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long v_ca1fdb = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = v_ca1fdb + iter_b; v_ca1fdb = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), v_ca1fdb, fib(40) == v_ca1fdb);
    return 0;
}
