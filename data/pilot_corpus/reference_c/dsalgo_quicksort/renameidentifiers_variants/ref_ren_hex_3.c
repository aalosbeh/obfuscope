#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_90df91, int v_5bf73d) {
    if (v_90df91 >= v_5bf73d) return;
    int p = a[v_5bf73d], i = v_90df91;
    for (int j = v_90df91; j < v_5bf73d; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_5bf73d]);
    qs(a, v_90df91, i - 1);
    qs(a, i + 1, v_5bf73d);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_f91cd2 = 0;
    for (int i = 0; i < 32; i++) v_f91cd2 += (long)a[i] * i;
    printf("%ld\n", v_f91cd2);
    return 0;
}
