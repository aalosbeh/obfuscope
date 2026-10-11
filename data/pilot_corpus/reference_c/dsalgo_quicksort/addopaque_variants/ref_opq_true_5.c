#include <stdio.h>
static volatile int opq_b4d3 = 7;
static volatile int opq_b4d3_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (((opq_b4d3 * opq_b4d3 - opq_b4d3) % 2 == 0)) { opq_b4d3_b ^= 0; }
    if (lo >= hi) return;
    if ((((opq_b4d3 * (opq_b4d3 + 1)) % 2) == 0)) { opq_b4d3_b ^= 0; }
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if (((opq_b4d3 * opq_b4d3 - opq_b4d3) % 2 == 0)) { opq_b4d3_b ^= 0; }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_b4d3 * opq_b4d3 + opq_b4d3) % 2) == 0)) { opq_b4d3_b ^= 0; }
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_b4d3 * (opq_b4d3 + 1)) % 2) == 0)) { opq_b4d3_b ^= 0; }
    printf("%ld\n", sum);
    if ((((opq_b4d3 * opq_b4d3 + opq_b4d3) % 2) == 0)) { opq_b4d3_b ^= 0; }
    return 0;
}
