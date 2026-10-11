#include <stdio.h>
static volatile int opq_6ba4 = 7;
static volatile int opq_6ba4_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_6ba4 * opq_6ba4) % 4) == 2)) {
        { int jv_1df0f = opq_6ba4 ^ 0x81A6;
            jv_1df0f += (jv_1df0f >> 2) + 0x91;
            jv_1df0f = (jv_1df0f * 0x3A) % 0x7FFFFFFF;
            jv_1df0f ^= (jv_1df0f << 3) | 0x85FB;
          (void)jv_1df0f; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if ((((opq_6ba4 * (opq_6ba4 + 1)) % 2) == 0)) { opq_6ba4_b ^= 0; }
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_6ba4 * opq_6ba4 + opq_6ba4_b * opq_6ba4_b) % 4) == 3)) {
        { int jv_78bd2 = opq_6ba4 ^ 0xD8AD;
            jv_78bd2 += (jv_78bd2 >> 2) + 0x29;
          (void)jv_78bd2; }
    }
    long sum = 0;
    if ((((opq_6ba4 * (opq_6ba4 + 1)) % 2) == 0)) { opq_6ba4_b ^= 0; }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    if ((((opq_6ba4 * (opq_6ba4 + 1)) % 2) == 0)) { opq_6ba4_b ^= 0; }
    printf("%ld\n", sum);
    if ((((opq_6ba4 * opq_6ba4 + opq_6ba4_b * opq_6ba4_b) % 4) == 3)) {
        { int jv_41201 = opq_6ba4 ^ 0x42F1;
            jv_41201 += (jv_41201 >> 2) + 0x3D;
            jv_41201 ^= (jv_41201 << 3) | 0x71BD;
            jv_41201 = (jv_41201 * 0x6) % 0x7FFFFFFF;
          (void)jv_41201; }
    }
    return 0;
}
