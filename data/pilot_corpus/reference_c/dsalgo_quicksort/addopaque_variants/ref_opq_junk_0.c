#include <stdio.h>
static volatile int opq_5398 = 7;
static volatile int opq_5398_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if ((((opq_5398 * opq_5398 + opq_5398_b * opq_5398_b) % 4) == 3)) {
        { int jv_61a75 = opq_5398 ^ 0xB906;
            jv_61a75 += (jv_61a75 >> 2) + 0x58;
            jv_61a75 = (jv_61a75 * 0x2C) % 0x7FFFFFFF;
          (void)jv_61a75; }
    }
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    if ((((opq_5398 * opq_5398) % 4) == 2)) {
        { int jv_df5b5 = opq_5398 ^ 0x26DE;
            jv_df5b5 += (jv_df5b5 >> 2) + 0xAB;
            jv_df5b5 = (jv_df5b5 * 0x27) % 0x7FFFFFFF;
            jv_df5b5 ^= (jv_df5b5 << 3) | 0xE47A;
          (void)jv_df5b5; }
    }
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    if ((((opq_5398 * opq_5398) % 4) == 2)) {
        { int jv_420ed = opq_5398 ^ 0xCEDE;
            jv_420ed ^= (jv_420ed << 3) | 0x8646;
            jv_420ed += (jv_420ed >> 2) + 0x95;
          (void)jv_420ed; }
    }
    qs(a, i + 1, hi);
}
int main(void) {
    if ((((opq_5398 * opq_5398 + opq_5398_b * opq_5398_b) % 4) == 3)) {
        { int jv_73d64 = opq_5398 ^ 0x51CE;
            jv_73d64 ^= (jv_73d64 << 3) | 0x3FE2;
            jv_73d64 = (jv_73d64 * 0x4) % 0x7FFFFFFF;
            jv_73d64 += (jv_73d64 >> 2) + 0xEC;
          (void)jv_73d64; }
    }
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    if ((((opq_5398 * opq_5398) % 4) == 2)) {
        { int jv_1c781 = opq_5398 ^ 0x4951;
            jv_1c781 += (jv_1c781 >> 2) + 0x71;
            jv_1c781 = (jv_1c781 * 0x7) % 0x7FFFFFFF;
          (void)jv_1c781; }
    }
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    if ((((opq_5398 * opq_5398) % 4) == 2)) {
        { int jv_8f075 = opq_5398 ^ 0x64AF;
            jv_8f075 += (jv_8f075 >> 2) + 0xCA;
          (void)jv_8f075; }
    }
    return 0;
}
