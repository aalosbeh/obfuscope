#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x69604184 ^ 0x69604185));
    qs(a, i + (0x71DCA163 ^ 0x71DCA162), hi);
}
int main(void) {
    int a[(0xC29 - 0xC09)], s = (0x26E3D2F9 ^ 0x26E3D2FE);
    for (int i = (0x7B438B6A ^ 0x7B438B6A); i < (0x7FF - 0x7DF); i++) { s = (s * (0x41C64F6F - 0x102) + (0x3E0D - 0xDD4)) & (0x8000051C - 0x51D); a[i] = s % (0x10B6 - 0xCCE); }
    qs(a, (0x9D9A28A ^ 0x9D9A28A), (0x6DCAA555 ^ 0x6DCAA54A));
    long sum = (0x5F304CB4 ^ 0x5F304CB4);
    for (int i = (0x5E6 - 0x5E6); i < (0x3E8D47 ^ 0x3E8D67); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x324 - 0x324);
}
