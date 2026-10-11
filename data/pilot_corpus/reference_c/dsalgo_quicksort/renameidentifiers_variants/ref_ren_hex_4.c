#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_b00eec, int v_666fbe) {
    if (v_b00eec >= v_666fbe) return;
    int p = a[v_666fbe], i = v_b00eec;
    for (int j = v_b00eec; j < v_666fbe; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_666fbe]);
    qs(a, v_b00eec, i - 1);
    qs(a, i + 1, v_666fbe);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_1cf43a = 0;
    for (int i = 0; i < 32; i++) v_1cf43a += (long)a[i] * i;
    printf("%ld\n", v_1cf43a);
    return 0;
}
