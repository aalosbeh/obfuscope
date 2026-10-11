#include <stdio.h>
static long tanzvfneyvrctpzeuf[64];
static long fib(int n) {
    if (n < 2) return n;
    if (tanzvfneyvrctpzeuf[n]) return tanzvfneyvrctpzeuf[n];
    return tanzvfneyvrctpzeuf[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long putzjoydgjoyus = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = putzjoydgjoyus + iter_b; putzjoydgjoyus = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), putzjoydgjoyus, fib(40) == putzjoydgjoyus);
    return 0;
}
