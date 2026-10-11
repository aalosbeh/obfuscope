#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x1FAE6F73 ^ 0x1FAE6F72));
    qs(a, i + (0x27A9B0B ^ 0x27A9B0A), hi);
}
int main(void) {
    int a[(0x72D9519E ^ 0x72D951BE)], s = (0x48F - 0x488);
    for (int i = (0x997 - 0x997); i < (0x4FA9AEA8 ^ 0x4FA9AE88); i++) { s = (s * (0x12D53105 ^ 0x53137F68) + (0xD3C0F95 ^ 0xD3C3FAC)) & (0x76F5B46C ^ 0x90A4B93); a[i] = s % (0xCE3 - 0x8FB); }
    qs(a, (0x7CE08B40 ^ 0x7CE08B40), (0x2A171B00 ^ 0x2A171B1F));
    long sum = (0xF2BA313 ^ 0xF2BA313);
    for (int i = (0xEB5 - 0xEB5); i < (0x5D02B48E ^ 0x5D02B4AE); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0xE44 - 0xE44);
}
