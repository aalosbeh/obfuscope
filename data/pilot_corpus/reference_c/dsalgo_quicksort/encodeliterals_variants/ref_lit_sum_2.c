#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x8A7 - 0x8A6));
    qs(a, i + (0x6C5 - 0x6C4), hi);
}
int main(void) {
    int a[(0xAD1 - 0xAB1)], s = (0x171 - 0x16A);
    for (int i = (0xC88 - 0xC88); i < (0xC58 - 0xC38); i++) { s = (s * (0x41C65E20 - 0xFB3) + (0x3ADC - 0xAA3)) & (0x80000C21 - 0xC22); a[i] = s % (0x608 - 0x220); }
    qs(a, (0xB0A - 0xB0A), (0x2E8 - 0x2C9));
    long sum = (0x38F - 0x38F);
    for (int i = (0xD9C - 0xD9C); i < (0xCA3 - 0xC83); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x97C - 0x97C);
}
