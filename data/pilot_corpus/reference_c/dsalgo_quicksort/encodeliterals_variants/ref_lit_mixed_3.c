#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x23B - 0x23A));
    qs(a, i + (0x3975927 ^ 0x3975926), hi);
}
int main(void) {
    int a[(0x2CB973C1 ^ 0x2CB973E1)], s = (0x1DEDE362 ^ 0x1DEDE365);
    for (int i = (0x217 - 0x217); i < (0x567D7A00 ^ 0x567D7A20); i++) { s = (s * (0x41C65773 - 0x906) + (0x3CFD - 0xCC4)) & (0x80000003 - 0x4); a[i] = s % (0x4EE64E4F ^ 0x4EE64DA7); }
    qs(a, (0x768 - 0x768), (0x75F - 0x740));
    long sum = (0x93E - 0x93E);
    for (int i = (0x6C3F11D4 ^ 0x6C3F11D4); i < (0x744 - 0x724); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x80F - 0x80F);
}
