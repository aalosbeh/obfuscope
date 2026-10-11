#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_814813, int v_cb65da) {
    if (v_814813 >= v_cb65da) return;
    int p = a[v_cb65da], i = v_814813;
    for (int j = v_814813; j < v_cb65da; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_cb65da]);
    qs(a, v_814813, i - 1);
    qs(a, i + 1, v_cb65da);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_60f0ab = 0;
    for (int i = 0; i < 32; i++) v_60f0ab += (long)a[i] * i;
    printf("%ld\n", v_60f0ab);
    return 0;
}
