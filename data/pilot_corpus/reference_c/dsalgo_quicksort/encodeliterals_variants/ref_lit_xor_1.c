#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x3AD99236 ^ 0x3AD99237));
    qs(a, i + (0xACF2659 ^ 0xACF2658), hi);
}
int main(void) {
    int a[(0x5D10F1B7 ^ 0x5D10F197)], s = (0x3231BB68 ^ 0x3231BB6F);
    for (int i = (0x83F9A90 ^ 0x83F9A90); i < (0xFFF709 ^ 0xFFF729); i++) { s = (s * (0x7A329183 ^ 0x3BF4DFEE) + (0x51A3C69E ^ 0x51A3F6A7)) & (0x622D8CC4 ^ 0x1DD2733B); a[i] = s % (0x19BF5380 ^ 0x19BF5068); }
    qs(a, (0x71F13828 ^ 0x71F13828), (0x4D906B97 ^ 0x4D906B88));
    long sum = (0x494FD2A1 ^ 0x494FD2A1);
    for (int i = (0x4B75C0BA ^ 0x4B75C0BA); i < (0x5E591CC1 ^ 0x5E591CE1); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x2CA31918 ^ 0x2CA31918);
}
