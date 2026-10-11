#include <stdio.h>
static long cfawreehjmzkdjltsynvib[64];
static long fib(int n) {
    if (n < 2) return n;
    if (cfawreehjmzkdjltsynvib[n]) return cfawreehjmzkdjltsynvib[n];
    return cfawreehjmzkdjltsynvib[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long ldietnqvaexvuijam = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = ldietnqvaexvuijam + iter_b; ldietnqvaexvuijam = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), ldietnqvaexvuijam, fib(40) == ldietnqvaexvuijam);
    return 0;
}
