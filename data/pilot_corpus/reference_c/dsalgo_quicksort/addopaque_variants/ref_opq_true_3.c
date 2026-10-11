#include <stdio.h>
static volatile int opq_2283 = 7;
static volatile int opq_2283_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if ((((opq_2283 * (opq_2283 + 1)) % 2) == 0)) { opq_2283_b ^= 0; }
    int p = a[hi], i = lo;
    if (((opq_2283 * opq_2283 - opq_2283) % 2 == 0)) { opq_2283_b ^= 0; }
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_2283 * opq_2283 + opq_2283) % 2) == 0)) { opq_2283_b ^= 0; }
    swap(&a[i], &a[hi]);
    if ((((opq_2283 * opq_2283 + opq_2283) % 2) == 0)) { opq_2283_b ^= 0; }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if ((((opq_2283 * (opq_2283 + 1)) % 2) == 0)) { opq_2283_b ^= 0; }
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_2283 * (opq_2283 + 1)) % 2) == 0)) { opq_2283_b ^= 0; }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
