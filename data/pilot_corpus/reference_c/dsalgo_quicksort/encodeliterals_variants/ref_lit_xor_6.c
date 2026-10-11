#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x59DAA3E2 ^ 0x59DAA3E3));
    qs(a, i + (0x74B46208 ^ 0x74B46209), hi);
}
int main(void) {
    int a[(0x781118BC ^ 0x7811189C)], s = (0x478E4FB3 ^ 0x478E4FB4);
    for (int i = (0x3F1506D ^ 0x3F1506D); i < (0x1EF5F371 ^ 0x1EF5F351); i++) { s = (s * (0x60E57C8B ^ 0x212332E6) + (0x3A5FE7B ^ 0x3A5CE42)) & (0x46AEC089 ^ 0x39513F76); a[i] = s % (0x2A0CE7F0 ^ 0x2A0CE418); }
    qs(a, (0x3378871E ^ 0x3378871E), (0x13B20D3 ^ 0x13B20CC));
    long sum = (0x814D8C6 ^ 0x814D8C6);
    for (int i = (0x23EB7843 ^ 0x23EB7843); i < (0x3C42880 ^ 0x3C428A0); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x74CD0967 ^ 0x74CD0967);
}
