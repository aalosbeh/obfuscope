#include <stdio.h>
static volatile int opq_21b4 = 7;
static volatile int opq_21b4_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_21b4 * opq_21b4) % 4) == 2)) {
        { int jv_35e72 = opq_21b4 ^ 0x5D81;
            jv_35e72 ^= (jv_35e72 << 3) | 0xF198;
            jv_35e72 = (jv_35e72 * 0x3D) % 0x7FFFFFFF;
          (void)jv_35e72; }
    }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_21b4 * opq_21b4) % 4) == 2)) {
        { int jv_ba2e6 = opq_21b4 ^ 0x6AA6;
            jv_ba2e6 = (jv_ba2e6 * 0x1C) % 0x7FFFFFFF;
            jv_ba2e6 ^= (jv_ba2e6 << 3) | 0xF205;
          (void)jv_ba2e6; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if ((((opq_21b4 * opq_21b4) % 4) == 2)) {
        { int jv_56880 = opq_21b4 ^ 0x4163;
            jv_56880 ^= (jv_56880 << 3) | 0x7878;
            jv_56880 = (jv_56880 * 0x9) % 0x7FFFFFFF;
          (void)jv_56880; }
    }
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_21b4 * opq_21b4) % 4) == 2)) {
        { int jv_69884 = opq_21b4 ^ 0xDF28;
            jv_69884 ^= (jv_69884 << 3) | 0x8D10;
            jv_69884 += (jv_69884 >> 2) + 0x63;
            jv_69884 = (jv_69884 * 0xA) % 0x7FFFFFFF;
          (void)jv_69884; }
    }
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_21b4 * opq_21b4 + opq_21b4_b * opq_21b4_b) % 4) == 3)) {
        { int jv_8a532 = opq_21b4 ^ 0x1B70;
            jv_8a532 ^= (jv_8a532 << 3) | 0xE04;
            jv_8a532 = (jv_8a532 * 0x8) % 0x7FFFFFFF;
          (void)jv_8a532; }
    }
    printf("%ld\n", sum);
    if ((((opq_21b4 * opq_21b4 + opq_21b4_b * opq_21b4_b) % 4) == 3)) {
        { int jv_260be = opq_21b4 ^ 0xB83D;
            jv_260be ^= (jv_260be << 3) | 0xD126;
          (void)jv_260be; }
    }
    return 0;
}
