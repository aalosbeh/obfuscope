#include <stdio.h>
static volatile int opq_531e = 7;
static volatile int opq_531e_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_531e * opq_531e + opq_531e_b * opq_531e_b) % 4) == 3)) {
        { int jv_b8e65 = opq_531e ^ 0x1B21;
            jv_b8e65 ^= (jv_b8e65 << 3) | 0x6450;
          (void)jv_b8e65; }
    }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_531e * opq_531e + opq_531e) % 2) == 0)) { opq_531e_b ^= 0; }
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    if ((((opq_531e * opq_531e + opq_531e) % 2) == 0)) { opq_531e_b ^= 0; }
    int a[32], s = 7;
    if ((((opq_531e * opq_531e + opq_531e_b * opq_531e_b) % 4) == 3)) {
        { int jv_7f21e = opq_531e ^ 0x31CC;
            jv_7f21e = (jv_7f21e * 0x16) % 0x7FFFFFFF;
            jv_7f21e += (jv_7f21e >> 2) + 0xF7;
            jv_7f21e ^= (jv_7f21e << 3) | 0x4C79;
          (void)jv_7f21e; }
    }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if (((opq_531e * opq_531e - opq_531e) % 2 == 0)) { opq_531e_b ^= 0; }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_531e * opq_531e + opq_531e) % 2) == 0)) { opq_531e_b ^= 0; }
    printf("%ld\n", sum);
    return 0;
}
