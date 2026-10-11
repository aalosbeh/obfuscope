#include <stdio.h>
static volatile int opq_dfd8 = 7;
static volatile int opq_dfd8_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if (((opq_dfd8 * opq_dfd8 - opq_dfd8) % 2 == 0)) { opq_dfd8_b ^= 0; }
    int p = a[hi], i = lo;
    if (((opq_dfd8 * opq_dfd8 - opq_dfd8) % 2 == 0)) { opq_dfd8_b ^= 0; }
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_dfd8 * opq_dfd8 + opq_dfd8) % 2) == 0)) { opq_dfd8_b ^= 0; }
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    if ((((opq_dfd8 * opq_dfd8 + opq_dfd8_b * opq_dfd8_b) % 4) == 3)) {
        { int jv_e8c81 = opq_dfd8 ^ 0xE0DD;
            jv_e8c81 ^= (jv_e8c81 << 3) | 0x797E;
            jv_e8c81 += (jv_e8c81 >> 2) + 0xB4;
            jv_e8c81 = (jv_e8c81 * 0x2C) % 0x7FFFFFFF;
          (void)jv_e8c81; }
    }
    qs(a, i + 1, hi);
    if ((((opq_dfd8 * opq_dfd8 + opq_dfd8_b * opq_dfd8_b) % 4) == 3)) {
        { int jv_73459 = opq_dfd8 ^ 0xE911;
            jv_73459 ^= (jv_73459 << 3) | 0x2532;
          (void)jv_73459; }
    }
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if ((((opq_dfd8 * opq_dfd8) % 4) == 2)) {
        { int jv_45d8c = opq_dfd8 ^ 0x84A;
            jv_45d8c = (jv_45d8c * 0x3) % 0x7FFFFFFF;
            jv_45d8c += (jv_45d8c >> 2) + 0x11;
          (void)jv_45d8c; }
    }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
