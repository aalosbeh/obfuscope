#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_4683a5, int v_35aad4) {
    if (v_4683a5 >= v_35aad4) return;
    int p = a[v_35aad4], i = v_4683a5;
    for (int j = v_4683a5; j < v_35aad4; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_35aad4]);
    qs(a, v_4683a5, i - 1);
    qs(a, i + 1, v_35aad4);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_99118b = 0;
    for (int i = 0; i < 32; i++) v_99118b += (long)a[i] * i;
    printf("%ld\n", v_99118b);
    return 0;
}
