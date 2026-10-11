#include <stdio.h>
static long aomwcybghhqpydy[64];
static long fib(int n) {
    if (n < 2) return n;
    if (aomwcybghhqpydy[n]) return aomwcybghhqpydy[n];
    return aomwcybghhqpydy[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long rsavybdysulginmeemn = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = rsavybdysulginmeemn + iter_b; rsavybdysulginmeemn = iter_b; iter_b = t; }
    printf("%ld %ld %d\n", fib(40), rsavybdysulginmeemn, fib(40) == rsavybdysulginmeemn);
    return 0;
}
