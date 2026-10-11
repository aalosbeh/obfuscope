#include <stdio.h>
static volatile int opq_6489 = 7;
static volatile int opq_6489_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_6489 * opq_6489) % 4) == 2)) {
        { int jv_6b0a6 = opq_6489 ^ 0x6FD5;
            jv_6b0a6 ^= (jv_6b0a6 << 3) | 0x3EE0;
          (void)jv_6b0a6; }
    }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_6489 * opq_6489 + opq_6489_b * opq_6489_b) % 4) == 3)) {
        { int jv_6ac4b = opq_6489 ^ 0x1D34;
            jv_6ac4b += (jv_6ac4b >> 2) + 0x43;
            jv_6ac4b = (jv_6ac4b * 0x2E) % 0x7FFFFFFF;
            jv_6ac4b ^= (jv_6ac4b << 3) | 0x5933;
          (void)jv_6ac4b; }
    }
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    if ((((opq_6489 * opq_6489 + opq_6489_b * opq_6489_b) % 4) == 3)) {
        { int jv_2ed58 = opq_6489 ^ 0x2C4;
            jv_2ed58 = (jv_2ed58 * 0x3A) % 0x7FFFFFFF;
            jv_2ed58 ^= (jv_2ed58 << 3) | 0xF6D3;
          (void)jv_2ed58; }
    }
    qs(a, i + 1, hi);
    if ((((opq_6489 * opq_6489 + opq_6489_b * opq_6489_b) % 4) == 3)) {
        { int jv_6c671 = opq_6489 ^ 0x153A;
            jv_6c671 ^= (jv_6c671 << 3) | 0xA1CC;
            jv_6c671 += (jv_6c671 >> 2) + 0xBC;
          (void)jv_6c671; }
    }
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_6489 * opq_6489) % 4) == 2)) {
        { int jv_95cac = opq_6489 ^ 0xE55F;
            jv_95cac ^= (jv_95cac << 3) | 0xAAA1;
          (void)jv_95cac; }
    }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_6489 * opq_6489 + opq_6489_b * opq_6489_b) % 4) == 3)) {
        { int jv_1bdac = opq_6489 ^ 0x2B19;
            jv_1bdac ^= (jv_1bdac << 3) | 0x4C73;
            jv_1bdac += (jv_1bdac >> 2) + 0x1;
          (void)jv_1bdac; }
    }
    printf("%ld\n", sum);
    return 0;
}
