#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int kgkulcgglqzevxuarslx, int tfsderigomozyszbtfur) {
    if (kgkulcgglqzevxuarslx >= tfsderigomozyszbtfur) return;
    int p = a[tfsderigomozyszbtfur], i = kgkulcgglqzevxuarslx;
    for (int j = kgkulcgglqzevxuarslx; j < tfsderigomozyszbtfur; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[tfsderigomozyszbtfur]);
    qs(a, kgkulcgglqzevxuarslx, i - 1);
    qs(a, i + 1, tfsderigomozyszbtfur);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long cbgbbjkmhenkrvjzpliosz = 0;
    for (int i = 0; i < 32; i++) cbgbbjkmhenkrvjzpliosz += (long)a[i] * i;
    printf("%ld\n", cbgbbjkmhenkrvjzpliosz);
    return 0;
}
