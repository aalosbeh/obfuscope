#include <stdio.h>
static volatile int opq_1817 = 7;
static volatile int opq_1817_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_1817 * opq_1817) % 4) == 2)) {
        { int jv_155fe = opq_1817 ^ 0x9D96;
            jv_155fe ^= (jv_155fe << 3) | 0x104E;
            jv_155fe += (jv_155fe >> 2) + 0xD;
          (void)jv_155fe; }
    }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_1817 * opq_1817) % 4) == 2)) {
        { int jv_8e769 = opq_1817 ^ 0xC46B;
            jv_8e769 ^= (jv_8e769 << 3) | 0xFC31;
          (void)jv_8e769; }
    }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if ((((opq_1817 * opq_1817) % 4) == 2)) {
        { int jv_c9b42 = opq_1817 ^ 0x217;
            jv_c9b42 ^= (jv_c9b42 << 3) | 0x3492;
            jv_c9b42 = (jv_c9b42 * 0x19) % 0x7FFFFFFF;
            jv_c9b42 += (jv_c9b42 >> 2) + 0xD5;
          (void)jv_c9b42; }
    }
}
int main(void) {
    if ((((opq_1817 * opq_1817) % 4) == 2)) {
        { int jv_41568 = opq_1817 ^ 0xB332;
            jv_41568 += (jv_41568 >> 2) + 0x5C;
            jv_41568 ^= (jv_41568 << 3) | 0x6BAB;
            jv_41568 = (jv_41568 * 0x1F) % 0x7FFFFFFF;
          (void)jv_41568; }
    }
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if ((((opq_1817 * opq_1817 + opq_1817_b * opq_1817_b) % 4) == 3)) {
        { int jv_e1e1a = opq_1817 ^ 0xFC97;
            jv_e1e1a ^= (jv_e1e1a << 3) | 0x8544;
            jv_e1e1a = (jv_e1e1a * 0x12) % 0x7FFFFFFF;
            jv_e1e1a += (jv_e1e1a >> 2) + 0x98;
          (void)jv_e1e1a; }
    }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    if ((((opq_1817 * opq_1817 + opq_1817_b * opq_1817_b) % 4) == 3)) {
        { int jv_ca594 = opq_1817 ^ 0x9D61;
            jv_ca594 += (jv_ca594 >> 2) + 0x1D;
            jv_ca594 ^= (jv_ca594 << 3) | 0x3ACA;
          (void)jv_ca594; }
    }
    return 0;
}
