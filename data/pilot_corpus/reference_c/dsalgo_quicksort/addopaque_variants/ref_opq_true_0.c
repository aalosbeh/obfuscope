#include <stdio.h>
static volatile int opq_29b6 = 7;
static volatile int opq_29b6_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_29b6 * opq_29b6 + opq_29b6) % 2) == 0)) { opq_29b6_b ^= 0; }
    if (lo >= hi) return;
    if ((((opq_29b6 * (opq_29b6 + 1)) % 2) == 0)) { opq_29b6_b ^= 0; }
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if ((((opq_29b6 * (opq_29b6 + 1)) % 2) == 0)) { opq_29b6_b ^= 0; }
}
int main(void) {
    if ((((opq_29b6 * opq_29b6 + opq_29b6) % 2) == 0)) { opq_29b6_b ^= 0; }
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if (((opq_29b6 * opq_29b6 - opq_29b6) % 2 == 0)) { opq_29b6_b ^= 0; }
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if (((opq_29b6 * opq_29b6 - opq_29b6) % 2 == 0)) { opq_29b6_b ^= 0; }
    printf("%ld\n", sum);
    return 0;
}
