#include <stdio.h>
static volatile int opq_850c = 7;
static volatile int opq_850c_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_850c * opq_850c + opq_850c_b * opq_850c_b) % 4) == 3)) {
        { int jv_57dc8 = opq_850c ^ 0x65C6;
            jv_57dc8 += (jv_57dc8 >> 2) + 0x20;
            jv_57dc8 ^= (jv_57dc8 << 3) | 0x2B7E;
          (void)jv_57dc8; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_850c * opq_850c + opq_850c_b * opq_850c_b) % 4) == 3)) {
        { int jv_9fd5f = opq_850c ^ 0x79E9;
            jv_9fd5f = (jv_9fd5f * 0x17) % 0x7FFFFFFF;
            jv_9fd5f += (jv_9fd5f >> 2) + 0x82;
          (void)jv_9fd5f; }
    }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_850c * opq_850c) % 4) == 2)) {
        { int jv_ddda5 = opq_850c ^ 0xF103;
            jv_ddda5 = (jv_ddda5 * 0x9) % 0x7FFFFFFF;
            jv_ddda5 ^= (jv_ddda5 << 3) | 0x6299;
            jv_ddda5 += (jv_ddda5 >> 2) + 0x80;
          (void)jv_ddda5; }
    }
    long sum = 0;
    if ((((opq_850c * opq_850c + opq_850c_b * opq_850c_b) % 4) == 3)) {
        { int jv_802d1 = opq_850c ^ 0xF02E;
            jv_802d1 += (jv_802d1 >> 2) + 0x9;
            jv_802d1 = (jv_802d1 * 0x13) % 0x7FFFFFFF;
            jv_802d1 ^= (jv_802d1 << 3) | 0x230;
          (void)jv_802d1; }
    }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_850c * opq_850c + opq_850c_b * opq_850c_b) % 4) == 3)) {
        { int jv_318a8 = opq_850c ^ 0x3E78;
            jv_318a8 = (jv_318a8 * 0x6) % 0x7FFFFFFF;
          (void)jv_318a8; }
    }
    printf("%ld\n", sum);
    if ((((opq_850c * opq_850c) % 4) == 2)) {
        { int jv_6f761 = opq_850c ^ 0x4E76;
            jv_6f761 ^= (jv_6f761 << 3) | 0x8C55;
            jv_6f761 = (jv_6f761 * 0x36) % 0x7FFFFFFF;
          (void)jv_6f761; }
    }
    return 0;
}
