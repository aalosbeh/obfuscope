#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x2B4 - 0x2B3));
    qs(a, i + (0x528 - 0x527), hi);
}
int main(void) {
    int a[(0xB56 - 0xB36)], s = (0x2B5 - 0x2AE);
    for (int i = (0x836 - 0x836); i < (0x362 - 0x342); i++) { s = (s * (0x41C65D50 - 0xEE3) + (0x3C34 - 0xBFB)) & (0x80000DBA - 0xDBB); a[i] = s % (0x119A - 0xDB2); }
    qs(a, (0x99B - 0x99B), (0xD75 - 0xD56));
    long sum = (0x90E - 0x90E);
    for (int i = (0x76D - 0x76D); i < (0x1B8 - 0x198); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x75E - 0x75E);
}
