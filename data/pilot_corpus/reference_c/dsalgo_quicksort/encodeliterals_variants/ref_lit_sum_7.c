#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x8F0 - 0x8EF));
    qs(a, i + (0x2BA - 0x2B9), hi);
}
int main(void) {
    int a[(0xF60 - 0xF40)], s = (0x1D - 0x16);
    for (int i = (0x96C - 0x96C); i < (0x7FA - 0x7DA); i++) { s = (s * (0x41C659FB - 0xB8E) + (0x3296 - 0x25D)) & (0x80000773 - 0x774); a[i] = s % (0x569 - 0x181); }
    qs(a, (0xC0 - 0xC0), (0xDD7 - 0xDB8));
    long sum = (0xA31 - 0xA31);
    for (int i = (0x970 - 0x970); i < (0xAD1 - 0xAB1); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0xF63 - 0xF63);
}
