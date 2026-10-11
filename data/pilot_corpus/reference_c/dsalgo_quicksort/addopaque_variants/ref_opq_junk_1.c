#include <stdio.h>
static volatile int opq_ebcb = 7;
static volatile int opq_ebcb_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if ((((opq_ebcb * opq_ebcb + opq_ebcb_b * opq_ebcb_b) % 4) == 3)) {
        { int jv_958f4 = opq_ebcb ^ 0x981E;
            jv_958f4 += (jv_958f4 >> 2) + 0xD4;
          (void)jv_958f4; }
    }
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_ebcb * opq_ebcb + opq_ebcb_b * opq_ebcb_b) % 4) == 3)) {
        { int jv_ae422 = opq_ebcb ^ 0x477B;
            jv_ae422 = (jv_ae422 * 0x20) % 0x7FFFFFFF;
          (void)jv_ae422; }
    }
    qs(a, lo, i - 1);
    if ((((opq_ebcb * opq_ebcb) % 4) == 2)) {
        { int jv_b7f10 = opq_ebcb ^ 0xD358;
            jv_b7f10 = (jv_b7f10 * 0x3) % 0x7FFFFFFF;
          (void)jv_b7f10; }
    }
    qs(a, i + 1, hi);
    if ((((opq_ebcb * opq_ebcb) % 4) == 2)) {
        { int jv_58c71 = opq_ebcb ^ 0x8827;
            jv_58c71 ^= (jv_58c71 << 3) | 0xC908;
          (void)jv_58c71; }
    }
}
int main(void) {
    if ((((opq_ebcb * opq_ebcb) % 4) == 2)) {
        { int jv_714c3 = opq_ebcb ^ 0xD51A;
            jv_714c3 += (jv_714c3 >> 2) + 0xDB;
          (void)jv_714c3; }
    }
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if ((((opq_ebcb * opq_ebcb) % 4) == 2)) {
        { int jv_35236 = opq_ebcb ^ 0x9A2F;
            jv_35236 += (jv_35236 >> 2) + 0x87;
            jv_35236 ^= (jv_35236 << 3) | 0x9C61;
            jv_35236 = (jv_35236 * 0xE) % 0x7FFFFFFF;
          (void)jv_35236; }
    }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
