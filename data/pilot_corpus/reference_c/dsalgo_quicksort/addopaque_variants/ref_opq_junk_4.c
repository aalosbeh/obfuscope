#include <stdio.h>
static volatile int opq_2437 = 7;
static volatile int opq_2437_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_2437 * opq_2437 + opq_2437_b * opq_2437_b) % 4) == 3)) {
        { int jv_bd953 = opq_2437 ^ 0x1EF7;
            jv_bd953 += (jv_bd953 >> 2) + 0xC1;
            jv_bd953 = (jv_bd953 * 0x17) % 0x7FFFFFFF;
            jv_bd953 ^= (jv_bd953 << 3) | 0x311;
          (void)jv_bd953; }
    }
    swap(&a[i], &a[hi]);
    if ((((opq_2437 * opq_2437 + opq_2437_b * opq_2437_b) % 4) == 3)) {
        { int jv_7d721 = opq_2437 ^ 0xE395;
            jv_7d721 = (jv_7d721 * 0x2B) % 0x7FFFFFFF;
            jv_7d721 ^= (jv_7d721 << 3) | 0xB111;
            jv_7d721 += (jv_7d721 >> 2) + 0x9F;
          (void)jv_7d721; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if ((((opq_2437 * opq_2437 + opq_2437_b * opq_2437_b) % 4) == 3)) {
        { int jv_bd9e8 = opq_2437 ^ 0x4DFE;
            jv_bd9e8 ^= (jv_bd9e8 << 3) | 0xE578;
          (void)jv_bd9e8; }
    }
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if ((((opq_2437 * opq_2437) % 4) == 2)) {
        { int jv_e87b8 = opq_2437 ^ 0xB975;
            jv_e87b8 = (jv_e87b8 * 0x7) % 0x7FFFFFFF;
          (void)jv_e87b8; }
    }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_2437 * opq_2437 + opq_2437_b * opq_2437_b) % 4) == 3)) {
        { int jv_c4ca2 = opq_2437 ^ 0x2E4B;
            jv_c4ca2 = (jv_c4ca2 * 0x34) % 0x7FFFFFFF;
          (void)jv_c4ca2; }
    }
    printf("%ld\n", sum);
    if ((((opq_2437 * opq_2437 + opq_2437_b * opq_2437_b) % 4) == 3)) {
        { int jv_87cfb = opq_2437 ^ 0xDA7A;
            jv_87cfb = (jv_87cfb * 0xF) % 0x7FFFFFFF;
            jv_87cfb ^= (jv_87cfb << 3) | 0x7564;
          (void)jv_87cfb; }
    }
    return 0;
}
