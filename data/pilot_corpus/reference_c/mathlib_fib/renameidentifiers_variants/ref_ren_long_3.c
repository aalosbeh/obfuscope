#include <stdio.h>
static long urntyigfjeddhumf[64];
static long fib(int n) {
    if (n < 2) return n;
    if (urntyigfjeddhumf[n]) return urntyigfjeddhumf[n];
    return urntyigfjeddhumf[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long tgyfywxzatyztjwxvumpt = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = tgyfywxzatyztjwxvumpt + iter_b; tgyfywxzatyztjwxvumpt = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), tgyfywxzatyztjwxvumpt, fib(40) == tgyfywxzatyztjwxvumpt);
    return 0;
}
