#include <stdio.h>
static volatile int opq_4373 = 7;
static volatile int opq_4373_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (((opq_4373 * opq_4373 - opq_4373) % 2 == 0)) { opq_4373_b ^= 0; }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_4373 * opq_4373 + opq_4373) % 2) == 0)) { opq_4373_b ^= 0; }
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_4373 * opq_4373 + opq_4373) % 2) == 0)) { opq_4373_b ^= 0; }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if ((((opq_4373 * opq_4373 + opq_4373) % 2) == 0)) { opq_4373_b ^= 0; }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_4373 * opq_4373 + opq_4373) % 2) == 0)) { opq_4373_b ^= 0; }
    printf("%ld\n", sum);
    if ((((opq_4373 * (opq_4373 + 1)) % 2) == 0)) { opq_4373_b ^= 0; }
    return 0;
}
