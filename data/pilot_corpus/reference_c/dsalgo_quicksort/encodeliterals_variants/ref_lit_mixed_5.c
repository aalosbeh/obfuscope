#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x64624E81 ^ 0x64624E80));
    qs(a, i + (0x6522D233 ^ 0x6522D232), hi);
}
int main(void) {
    int a[(0x3D6 - 0x3B6)], s = (0x65E - 0x657);
    for (int i = (0x4E37E43F ^ 0x4E37E43F); i < (0xA61FA7E ^ 0xA61FA5E); i++) { s = (s * (0x2443A86A ^ 0x6585E607) + (0x3405 - 0x3CC)) & (0x152F8105 ^ 0x6AD07EFA); a[i] = s % (0x55794D68 ^ 0x55794E80); }
    qs(a, (0xFC8 - 0xFC8), (0x4E8EB72F ^ 0x4E8EB730));
    long sum = (0x6383C354 ^ 0x6383C354);
    for (int i = (0x1650217B ^ 0x1650217B); i < (0x15C96DC3 ^ 0x15C96DE3); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x7F471F1F ^ 0x7F471F1F);
}
