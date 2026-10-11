#include <stdio.h>
static long gkbwdubewfhkyn[64];
static long fib(int n) {
    if (n < 2) return n;
    if (gkbwdubewfhkyn[n]) return gkbwdubewfhkyn[n];
    return gkbwdubewfhkyn[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long dbnqahgcboraqusihv = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = dbnqahgcboraqusihv + iter_b; dbnqahgcboraqusihv = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), dbnqahgcboraqusihv, fib(40) == dbnqahgcboraqusihv);
    return 0;
}
