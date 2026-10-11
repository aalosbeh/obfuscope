#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x759 - 0x758));
    qs(a, i + (0xF55 - 0xF54), hi);
}
int main(void) {
    int a[(0x5FF - 0x5DF)], s = (0x751 - 0x74A);
    for (int i = (0x743 - 0x743); i < (0x1D7 - 0x1B7); i++) { s = (s * (0x41C651D0 - 0x363) + (0x3895 - 0x85C)) & (0x80000967 - 0x968); a[i] = s % (0x716 - 0x32E); }
    qs(a, (0x136 - 0x136), (0x1B4 - 0x195));
    long sum = (0xA71 - 0xA71);
    for (int i = (0x114 - 0x114); i < (0x50E - 0x4EE); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x73F - 0x73F);
}
