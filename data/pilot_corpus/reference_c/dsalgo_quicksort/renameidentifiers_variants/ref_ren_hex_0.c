#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_92e2a2, int v_ed13f1) {
    if (v_92e2a2 >= v_ed13f1) return;
    int p = a[v_ed13f1], i = v_92e2a2;
    for (int j = v_92e2a2; j < v_ed13f1; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_ed13f1]);
    qs(a, v_92e2a2, i - 1);
    qs(a, i + 1, v_ed13f1);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_4512be = 0;
    for (int i = 0; i < 32; i++) v_4512be += (long)a[i] * i;
    printf("%ld\n", v_4512be);
    return 0;
}
