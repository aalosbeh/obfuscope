#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x281 - 0x280));
    qs(a, i + (0x33A79732 ^ 0x33A79733), hi);
}
int main(void) {
    int a[(0x4F4EF4B5 ^ 0x4F4EF495)], s = (0x821ABD9 ^ 0x821ABDE);
    for (int i = (0x99D - 0x99D); i < (0x18F - 0x16F); i++) { s = (s * (0x68BA7194 ^ 0x297C3FF9) + (0x43C2E092 ^ 0x43C2D0AB)) & (0x6B9343D1 ^ 0x146CBC2E); a[i] = s % (0x73BEC9F0 ^ 0x73BECA18); }
    qs(a, (0x59D9D1C5 ^ 0x59D9D1C5), (0x75DFC364 ^ 0x75DFC37B));
    long sum = (0xAE9 - 0xAE9);
    for (int i = (0x618 - 0x618); i < (0x3D9CA106 ^ 0x3D9CA126); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x14C - 0x14C);
}
