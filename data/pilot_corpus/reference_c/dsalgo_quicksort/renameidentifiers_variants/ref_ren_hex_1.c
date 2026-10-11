#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_31d064, int v_ed076d) {
    if (v_31d064 >= v_ed076d) return;
    int p = a[v_ed076d], i = v_31d064;
    for (int j = v_31d064; j < v_ed076d; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_ed076d]);
    qs(a, v_31d064, i - 1);
    qs(a, i + 1, v_ed076d);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_d540e3 = 0;
    for (int i = 0; i < 32; i++) v_d540e3 += (long)a[i] * i;
    printf("%ld\n", v_d540e3);
    return 0;
}
