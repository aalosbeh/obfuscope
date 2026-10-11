#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x5A3569C0 ^ 0x5A3569C1));
    qs(a, i + (0x50759E47 ^ 0x50759E46), hi);
}
int main(void) {
    int a[(0x746C9490 ^ 0x746C94B0)], s = (0xDA7CECE ^ 0xDA7CEC9);
    for (int i = (0xBEF3AE8 ^ 0xBEF3AE8); i < (0x29340E1C ^ 0x29340E3C); i++) { s = (s * (0x76B1F12E ^ 0x3777BF43) + (0xACF56F5 ^ 0xACF66CC)) & (0x66AB85B8 ^ 0x19547A47); a[i] = s % (0x126DD8C5 ^ 0x126DDB2D); }
    qs(a, (0x3BD5AF7E ^ 0x3BD5AF7E), (0x4570CDBA ^ 0x4570CDA5));
    long sum = (0x52B008BF ^ 0x52B008BF);
    for (int i = (0x7F013411 ^ 0x7F013411); i < (0x68051E1C ^ 0x68051E3C); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x50F70DD4 ^ 0x50F70DD4);
}
