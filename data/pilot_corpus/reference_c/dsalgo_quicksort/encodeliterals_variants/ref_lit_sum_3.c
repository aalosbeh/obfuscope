#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x2EC - 0x2EB));
    qs(a, i + (0x751 - 0x750), hi);
}
int main(void) {
    int a[(0xCEA - 0xCCA)], s = (0x387 - 0x380);
    for (int i = (0x14C - 0x14C); i < (0x63E - 0x61E); i++) { s = (s * (0x41C65BAC - 0xD3F) + (0x3E19 - 0xDE0)) & (0x80000D6D - 0xD6E); a[i] = s % (0x1194 - 0xDAC); }
    qs(a, (0xAE4 - 0xAE4), (0x173 - 0x154));
    long sum = (0xF0A - 0xF0A);
    for (int i = (0x70F - 0x70F); i < (0xA07 - 0x9E7); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0xD0C - 0xD0C);
}
