#include <stdio.h>
static volatile int opq_3e9a = 7;
static volatile int opq_3e9a_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if ((((opq_3e9a * opq_3e9a) % 4) == 2)) {
        { int jv_957a3 = opq_3e9a ^ 0x5DC7;
            jv_957a3 ^= (jv_957a3 << 3) | 0x4FE0;
            jv_957a3 = (jv_957a3 * 0x38) % 0x7FFFFFFF;
            jv_957a3 += (jv_957a3 >> 2) + 0x6C;
          (void)jv_957a3; }
    }
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_3e9a * opq_3e9a) % 4) == 2)) {
        { int jv_b55ed = opq_3e9a ^ 0x5AFE;
            jv_b55ed ^= (jv_b55ed << 3) | 0x38B3;
            jv_b55ed += (jv_b55ed >> 2) + 0xFB;
          (void)jv_b55ed; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    if ((((opq_3e9a * opq_3e9a + opq_3e9a_b * opq_3e9a_b) % 4) == 3)) {
        { int jv_7031a = opq_3e9a ^ 0x3CA7;
            jv_7031a ^= (jv_7031a << 3) | 0x42EC;
          (void)jv_7031a; }
    }
    int a[32], s = 7;
    if ((((opq_3e9a * opq_3e9a) % 4) == 2)) {
        { int jv_bf620 = opq_3e9a ^ 0xB5D1;
            jv_bf620 = (jv_bf620 * 0x3) % 0x7FFFFFFF;
          (void)jv_bf620; }
    }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_3e9a * opq_3e9a) % 4) == 2)) {
        { int jv_83f31 = opq_3e9a ^ 0xE184;
            jv_83f31 = (jv_83f31 * 0xA) % 0x7FFFFFFF;
          (void)jv_83f31; }
    }
    printf("%ld\n", sum);
    if ((((opq_3e9a * opq_3e9a) % 4) == 2)) {
        { int jv_2b4db = opq_3e9a ^ 0x1DC7;
            jv_2b4db += (jv_2b4db >> 2) + 0x81;
            jv_2b4db = (jv_2b4db * 0x8) % 0x7FFFFFFF;
            jv_2b4db ^= (jv_2b4db << 3) | 0xF1A;
          (void)jv_2b4db; }
    }
    return 0;
}
