#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x2096089B ^ 0x2096089A));
    qs(a, i + (0x712FABD8 ^ 0x712FABD9), hi);
}
int main(void) {
    int a[(0xB42E120 ^ 0xB42E100)], s = (0x11FF74BA ^ 0x11FF74BD);
    for (int i = (0x5E3C6F6B ^ 0x5E3C6F6B); i < (0x20062E69 ^ 0x20062E49); i++) { s = (s * (0x39DFCD74 ^ 0x78198319) + (0x6C37997B ^ 0x6C37A942)) & (0x325A5F6A ^ 0x4DA5A095); a[i] = s % (0x627FEAAB ^ 0x627FE943); }
    qs(a, (0x36E9CD12 ^ 0x36E9CD12), (0x319EF3D0 ^ 0x319EF3CF));
    long sum = (0x38FAE4E6 ^ 0x38FAE4E6);
    for (int i = (0x81B0EC1 ^ 0x81B0EC1); i < (0x35F65BC8 ^ 0x35F65BE8); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x675F68 ^ 0x675F68);
}
