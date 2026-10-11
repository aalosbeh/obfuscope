#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int v_636cae, int v_77e280) {
    if (v_636cae >= v_77e280) return;
    int p = a[v_77e280], i = v_636cae;
    for (int j = v_636cae; j < v_77e280; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[v_77e280]);
    qs(a, v_636cae, i - 1);
    qs(a, i + 1, v_77e280);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long v_a546c4 = 0;
    for (int i = 0; i < 32; i++) v_a546c4 += (long)a[i] * i;
    printf("%ld\n", v_a546c4);
    return 0;
}
