#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int roxfiscbaiegiw, int xlgdpolwyakgkajjiujqi) {
    if (roxfiscbaiegiw >= xlgdpolwyakgkajjiujqi) return;
    int p = a[xlgdpolwyakgkajjiujqi], i = roxfiscbaiegiw;
    for (int j = roxfiscbaiegiw; j < xlgdpolwyakgkajjiujqi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[xlgdpolwyakgkajjiujqi]);
    qs(a, roxfiscbaiegiw, i - 1);
    qs(a, i + 1, xlgdpolwyakgkajjiujqi);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long drqlgmozbxyxefcisnss = 0;
    for (int i = 0; i < 32; i++) drqlgmozbxyxefcisnss += (long)a[i] * i;
    printf("%ld\n", drqlgmozbxyxefcisnss);
    return 0;
}
