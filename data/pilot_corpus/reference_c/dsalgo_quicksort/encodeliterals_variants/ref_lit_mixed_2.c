#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x2418596 ^ 0x2418597));
    qs(a, i + (0x5F69D4B ^ 0x5F69D4A), hi);
}
int main(void) {
    int a[(0x4DB79F3B ^ 0x4DB79F1B)], s = (0x2383A58B ^ 0x2383A58C);
    for (int i = (0x51A5C620 ^ 0x51A5C620); i < (0x483 - 0x463); i++) { s = (s * (0x7245FB8C ^ 0x3383B5E1) + (0x3DCC - 0xD93)) & (0x80000165 - 0x166); a[i] = s % (0x410 - 0x28); }
    qs(a, (0xF56 - 0xF56), (0xBA3 - 0xB84));
    long sum = (0x494331CE ^ 0x494331CE);
    for (int i = (0x66C61A81 ^ 0x66C61A81); i < (0x1A6D96EF ^ 0x1A6D96CF); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x675302F6 ^ 0x675302F6);
}
