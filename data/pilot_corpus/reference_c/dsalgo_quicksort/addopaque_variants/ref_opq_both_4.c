#include <stdio.h>
static volatile int opq_345a = 7;
static volatile int opq_345a_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if ((((opq_345a * (opq_345a + 1)) % 2) == 0)) { opq_345a_b ^= 0; }
    int p = a[hi], i = lo;
    if ((((opq_345a * opq_345a + opq_345a) % 2) == 0)) { opq_345a_b ^= 0; }
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_345a * opq_345a) % 4) == 2)) {
        { int jv_e02d7 = opq_345a ^ 0x2E57;
            jv_e02d7 = (jv_e02d7 * 0x31) % 0x7FFFFFFF;
            jv_e02d7 += (jv_e02d7 >> 2) + 0x80;
            jv_e02d7 ^= (jv_e02d7 << 3) | 0x6956;
          (void)jv_e02d7; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_345a * opq_345a + opq_345a) % 2) == 0)) { opq_345a_b ^= 0; }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_345a * opq_345a) % 4) == 2)) {
        { int jv_47c2e = opq_345a ^ 0xCA83;
            jv_47c2e = (jv_47c2e * 0xB) % 0x7FFFFFFF;
            jv_47c2e += (jv_47c2e >> 2) + 0x76;
          (void)jv_47c2e; }
    }
    long sum = 0;
    if ((((opq_345a * opq_345a + opq_345a_b * opq_345a_b) % 4) == 3)) {
        { int jv_6d3d4 = opq_345a ^ 0x7B79;
            jv_6d3d4 += (jv_6d3d4 >> 2) + 0xE9;
            jv_6d3d4 = (jv_6d3d4 * 0x1C) % 0x7FFFFFFF;
            jv_6d3d4 ^= (jv_6d3d4 << 3) | 0xE4DA;
          (void)jv_6d3d4; }
    }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
