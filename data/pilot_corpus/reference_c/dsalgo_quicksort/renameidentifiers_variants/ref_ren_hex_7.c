#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_8c634f, int v_380005) {
    if (v_8c634f >= v_380005) return;
    int p = a[v_380005], i = v_8c634f;
    for (int j = v_8c634f; j < v_380005; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_380005]);
    qs(a, v_8c634f, i - 1);
    qs(a, i + 1, v_380005);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_cde49f = 0;
    for (int i = 0; i < 32; i++) v_cde49f += (long)a[i] * i;
    printf("%ld\n", v_cde49f);
    return 0;
}
