#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x181 - 0x180));
    qs(a, i + (0xEA0 - 0xE9F), hi);
}
int main(void) {
    int a[(0xC08 - 0xBE8)], s = (0x28A - 0x283);
    for (int i = (0xAA3 - 0xAA3); i < (0xEC7 - 0xEA7); i++) { s = (s * (0x41C6545E - 0x5F1) + (0x3781 - 0x748)) & (0x80000ADE - 0xADF); a[i] = s % (0xA30 - 0x648); }
    qs(a, (0xECE - 0xECE), (0xAEA - 0xACB));
    long sum = (0x5C9 - 0x5C9);
    for (int i = (0x360 - 0x360); i < (0xAE2 - 0xAC2); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x930 - 0x930);
}
