#include <stdio.h>
static volatile int opq_c1fb = 7;
static volatile int opq_c1fb_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if ((((opq_c1fb * opq_c1fb + opq_c1fb) % 2) == 0)) { opq_c1fb_b ^= 0; }
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_c1fb * opq_c1fb + opq_c1fb_b * opq_c1fb_b) % 4) == 3)) {
        { int jv_3a123 = opq_c1fb ^ 0xA464;
            jv_3a123 += (jv_3a123 >> 2) + 0x6A;
            jv_3a123 = (jv_3a123 * 0x2C) % 0x7FFFFFFF;
          (void)jv_3a123; }
    }
    swap(&a[i], &a[hi]);
    if ((((opq_c1fb * opq_c1fb + opq_c1fb) % 2) == 0)) { opq_c1fb_b ^= 0; }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    if ((((opq_c1fb * opq_c1fb + opq_c1fb_b * opq_c1fb_b) % 4) == 3)) {
        { int jv_2a376 = opq_c1fb ^ 0xF4B9;
            jv_2a376 = (jv_2a376 * 0x37) % 0x7FFFFFFF;
          (void)jv_2a376; }
    }
    int a[32], s = 7;
    if ((((opq_c1fb * opq_c1fb) % 4) == 2)) {
        { int jv_97097 = opq_c1fb ^ 0xF542;
            jv_97097 ^= (jv_97097 << 3) | 0x44CC;
          (void)jv_97097; }
    }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_c1fb * opq_c1fb + opq_c1fb_b * opq_c1fb_b) % 4) == 3)) {
        { int jv_e853d = opq_c1fb ^ 0x198A;
            jv_e853d = (jv_e853d * 0x16) % 0x7FFFFFFF;
          (void)jv_e853d; }
    }
    printf("%ld\n", sum);
    return 0;
}
