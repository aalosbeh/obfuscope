#include <stdio.h>
static long gezuzplyhravujwe[64];
static long fib(int n) {
    if (n < 2) return n;
    if (gezuzplyhravujwe[n]) return gezuzplyhravujwe[n];
    return gezuzplyhravujwe[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long dnuffilzobtwlgheymlhm = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = dnuffilzobtwlgheymlhm + iter_b; dnuffilzobtwlgheymlhm = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), dnuffilzobtwlgheymlhm, fib(40) == dnuffilzobtwlgheymlhm);
    return 0;
}
