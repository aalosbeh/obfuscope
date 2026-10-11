#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x3CE - 0x3CD));
    qs(a, i + (0x4AA - 0x4A9), hi);
}
int main(void) {
    int a[(0xAC5 - 0xAA5)], s = (0x454 - 0x44D);
    for (int i = (0xFAD - 0xFAD); i < (0xD60 - 0xD40); i++) { s = (s * (0x41C65C1F - 0xDB2) + (0x32D5 - 0x29C)) & (0x80000A8B - 0xA8C); a[i] = s % (0x607 - 0x21F); }
    qs(a, (0x6B7 - 0x6B7), (0x1F7 - 0x1D8));
    long sum = (0x7D0 - 0x7D0);
    for (int i = (0x7BA - 0x7BA); i < (0x2FC - 0x2DC); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x3F4 - 0x3F4);
}
