#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x4DD27E57 ^ 0x4DD27E56));
    qs(a, i + (0x32F - 0x32E), hi);
}
int main(void) {
    int a[(0x497 - 0x477)], s = (0xF30 - 0xF29);
    for (int i = (0xD83 - 0xD83); i < (0xA68 - 0xA48); i++) { s = (s * (0x43B5F1F8 ^ 0x273BF95) + (0x3CA1 - 0xC68)) & (0x7D950FC ^ 0x7826AF03); a[i] = s % (0xAFB - 0x713); }
    qs(a, (0x1716BFF8 ^ 0x1716BFF8), (0x585 - 0x566));
    long sum = (0x9859799 ^ 0x9859799);
    for (int i = (0x8EC - 0x8EC); i < (0xAA5 - 0xA85); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x775CF229 ^ 0x775CF229);
}
