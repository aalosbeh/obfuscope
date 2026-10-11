#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int cwdytvqmvwjshs, int cdbhvvynwvsqyvpc) {
    if (cwdytvqmvwjshs >= cdbhvvynwvsqyvpc) return;
    int p = a[cdbhvvynwvsqyvpc], i = cwdytvqmvwjshs;
    for (int j = cwdytvqmvwjshs; j < cdbhvvynwvsqyvpc; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[cdbhvvynwvsqyvpc]);
    qs(a, cwdytvqmvwjshs, i - 1);
    qs(a, i + 1, cdbhvvynwvsqyvpc);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long zcvwzkzjriuvixqqij = 0;
    for (int i = 0; i < 32; i++) zcvwzkzjriuvixqqij += (long)a[i] * i;
    printf("%ld\n", zcvwzkzjriuvixqqij);
    return 0;
}
