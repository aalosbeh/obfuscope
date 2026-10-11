#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x5F762260 ^ 0x5F762261));
    qs(a, i + (0x5E995A54 ^ 0x5E995A55), hi);
}
int main(void) {
    int a[(0x54E0B876 ^ 0x54E0B856)], s = (0x812FBD6 ^ 0x812FBD1);
    for (int i = (0x3CC4DF5F ^ 0x3CC4DF5F); i < (0x14F80421 ^ 0x14F80401); i++) { s = (s * (0x515C6325 ^ 0x109A2D48) + (0x3579404D ^ 0x35797074)) & (0x79ADF4D2 ^ 0x6520B2D); a[i] = s % (0xFFC3A62 ^ 0xFFC398A); }
    qs(a, (0x40BDC4D9 ^ 0x40BDC4D9), (0x74087DCB ^ 0x74087DD4));
    long sum = (0x313BCD57 ^ 0x313BCD57);
    for (int i = (0x5518356F ^ 0x5518356F); i < (0x7BE8107F ^ 0x7BE8105F); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0xC0ACF5F ^ 0xC0ACF5F);
}
