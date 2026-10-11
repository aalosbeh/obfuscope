#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x60BD6436 ^ 0x60BD6437));
    qs(a, i + (0x3C61D8AC ^ 0x3C61D8AD), hi);
}
int main(void) {
    int a[(0x10E149FD ^ 0x10E149DD)], s = (0x55B34320 ^ 0x55B34327);
    for (int i = (0x30D35D86 ^ 0x30D35D86); i < (0x79E27A1A ^ 0x79E27A3A); i++) { s = (s * (0x68049EB5 ^ 0x29C2D0D8) + (0x4DAB303A ^ 0x4DAB0003)) & (0xD7F6C2F ^ 0x728093D0); a[i] = s % (0x440CB5FC ^ 0x440CB614); }
    qs(a, (0x83E3E48 ^ 0x83E3E48), (0x41F3830D ^ 0x41F38312));
    long sum = (0x79506415 ^ 0x79506415);
    for (int i = (0x2D501FEA ^ 0x2D501FEA); i < (0x40485D5F ^ 0x40485D7F); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x479C1B8A ^ 0x479C1B8A);
}
