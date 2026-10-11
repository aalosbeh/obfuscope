#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x2567ED93 ^ 0x2567ED92));
    qs(a, i + (0x616578C2 ^ 0x616578C3), hi);
}
int main(void) {
    int a[(0x186AB944 ^ 0x186AB964)], s = (0x686B18B3 ^ 0x686B18B4);
    for (int i = (0x1DEAD5AE ^ 0x1DEAD5AE); i < (0xFD627F6 ^ 0xFD627D6); i++) { s = (s * (0x11B95A05 ^ 0x507F1468) + (0x4394257B ^ 0x43941542)) & (0x830AFAB ^ 0x77CF5054); a[i] = s % (0x2E38944F ^ 0x2E3897A7); }
    qs(a, (0x4DE7FF79 ^ 0x4DE7FF79), (0x710912B5 ^ 0x710912AA));
    long sum = (0x375C62D5 ^ 0x375C62D5);
    for (int i = (0x57E15D25 ^ 0x57E15D25); i < (0x7E282AB6 ^ 0x7E282A96); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x1894B5B9 ^ 0x1894B5B9);
}
