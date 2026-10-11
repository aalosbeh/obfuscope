#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0xED0 - 0xECF));
    qs(a, i + (0xE24 - 0xE23), hi);
}
int main(void) {
    int a[(0xD16 - 0xCF6)], s = (0x2AC - 0x2A5);
    for (int i = (0xB35 - 0xB35); i < (0x465 - 0x445); i++) { s = (s * (0x41C65CF1 - 0xE84) + (0x318A - 0x151)) & (0x80000C18 - 0xC19); a[i] = s % (0x544 - 0x15C); }
    qs(a, (0x6C2 - 0x6C2), (0x2C9 - 0x2AA));
    long sum = (0xEFA - 0xEFA);
    for (int i = (0x174 - 0x174); i < (0x5A0 - 0x580); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x732 - 0x732);
}
