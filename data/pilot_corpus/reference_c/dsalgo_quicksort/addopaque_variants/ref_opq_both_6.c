#include <stdio.h>
static volatile int opq_d242 = 7;
static volatile int opq_d242_b = 3;

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    if ((((opq_d242 * opq_d242) % 4) == 2)) {
        { int jv_e8005 = opq_d242 ^ 0x6E9C;
            jv_e8005 ^= (jv_e8005 << 3) | 0xC11C;
          (void)jv_e8005; }
    }
    int p = a[hi], i = lo;
    if ((((opq_d242 * opq_d242) % 4) == 2)) {
        { int jv_345f1 = opq_d242 ^ 0x15AC;
            jv_345f1 = (jv_345f1 * 0x37) % 0x7FFFFFFF;
            jv_345f1 ^= (jv_345f1 << 3) | 0x4F07;
          (void)jv_345f1; }
    }
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    if ((((opq_d242 * (opq_d242 + 1)) % 2) == 0)) { opq_d242_b ^= 0; }
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
    if (((opq_d242 * opq_d242 - opq_d242) % 2 == 0)) { opq_d242_b ^= 0; }
}
int main(void) {
    int a[32], s = 7;
    if ((((opq_d242 * (opq_d242 + 1)) % 2) == 0)) { opq_d242_b ^= 0; }
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    if (((opq_d242 * opq_d242 - opq_d242) % 2 == 0)) { opq_d242_b ^= 0; }
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return 0;
}
