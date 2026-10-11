#include <stdio.h>
static volatile int opq_2159 = 7;
static volatile int opq_2159_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    if ((((opq_2159 * opq_2159 + opq_2159_b * opq_2159_b) % 4) == 3)) {
        { int jv_6f750 = opq_2159 ^ 0x4F12;
            jv_6f750 ^= (jv_6f750 << 3) | 0xB1A6;
          (void)jv_6f750; }
    }
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_2159 * opq_2159) % 4) == 2)) {
        { int jv_2cbda = opq_2159 ^ 0x2A4F;
            jv_2cbda ^= (jv_2cbda << 3) | 0xF6CC;
          (void)jv_2cbda; }
    }
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    if ((((opq_2159 * (opq_2159 + 1)) % 2) == 0)) { opq_2159_b ^= 0; }
    qs(a, i + 1, hi);
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_2159 * opq_2159) % 4) == 2)) {
        { int jv_11e17 = opq_2159 ^ 0xA24E;
            jv_11e17 += (jv_11e17 >> 2) + 0xF4;
            jv_11e17 = (jv_11e17 * 0x1D) % 0x7FFFFFFF;
          (void)jv_11e17; }
    }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_2159 * opq_2159 + opq_2159_b * opq_2159_b) % 4) == 3)) {
        { int jv_f4774 = opq_2159 ^ 0x5E26;
            jv_f4774 = (jv_f4774 * 0x9) % 0x7FFFFFFF;
            jv_f4774 += (jv_f4774 >> 2) + 0xE4;
          (void)jv_f4774; }
    }
    long sum = 0;
    if ((((opq_2159 * (opq_2159 + 1)) % 2) == 0)) { opq_2159_b ^= 0; }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
