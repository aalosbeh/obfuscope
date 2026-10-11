#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int llhkrojlajrxhjfrupix, int vusjsisibidaide) {
    if (llhkrojlajrxhjfrupix >= vusjsisibidaide) return;
    int p = a[vusjsisibidaide], i = llhkrojlajrxhjfrupix;
    for (int j = llhkrojlajrxhjfrupix; j < vusjsisibidaide; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[vusjsisibidaide]);
    qs(a, llhkrojlajrxhjfrupix, i - 1);
    qs(a, i + 1, vusjsisibidaide);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long nzikucafrohgrr = 0;
    for (int i = 0; i < 32; i++) nzikucafrohgrr += (long)a[i] * i;
    printf("%ld\n", nzikucafrohgrr);
    return 0;
}
