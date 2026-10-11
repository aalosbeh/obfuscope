#include <stdio.h>
static volatile int opq_9c71 = 7;
static volatile int opq_9c71_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_9c71 * opq_9c71) % 4) == 2)) {
        { int jv_8a0a4 = opq_9c71 ^ 0xB143;
            jv_8a0a4 = (jv_8a0a4 * 0x2E) % 0x7FFFFFFF;
          (void)jv_8a0a4; }
    }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    if ((((opq_9c71 * opq_9c71 + opq_9c71) % 2) == 0)) { opq_9c71_b ^= 0; }
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_9c71 * opq_9c71 + opq_9c71_b * opq_9c71_b) % 4) == 3)) {
        { int jv_b40ad = opq_9c71 ^ 0x2358;
            jv_b40ad = (jv_b40ad * 0x11) % 0x7FFFFFFF;
            jv_b40ad ^= (jv_b40ad << 3) | 0x4C5;
            jv_b40ad += (jv_b40ad >> 2) + 0xC4;
          (void)jv_b40ad; }
    }
    swap(&a[i], &a[hi]);
    if (((opq_9c71 * opq_9c71 - opq_9c71) % 2 == 0)) { opq_9c71_b ^= 0; }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    if ((((opq_9c71 * opq_9c71 + opq_9c71_b * opq_9c71_b) % 4) == 3)) {
        { int jv_92285 = opq_9c71 ^ 0x73B1;
            jv_92285 += (jv_92285 >> 2) + 0xA4;
            jv_92285 ^= (jv_92285 << 3) | 0x5E70;
          (void)jv_92285; }
    }
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if (((opq_9c71 * opq_9c71 - opq_9c71) % 2 == 0)) { opq_9c71_b ^= 0; }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
