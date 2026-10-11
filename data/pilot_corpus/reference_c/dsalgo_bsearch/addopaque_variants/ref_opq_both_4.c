#include <stdio.h>
static volatile int opq_63f6 = 7;
static volatile int opq_63f6_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if (((opq_63f6 * opq_63f6 - opq_63f6) % 2 == 0)) { opq_63f6_b ^= 0; }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_63f6 * opq_63f6 + opq_63f6_b * opq_63f6_b) % 4) == 3)) {
            { int jv_b8f25 = opq_63f6 ^ 0x9EF;
                jv_b8f25 ^= (jv_b8f25 << 3) | 0x4A;
                jv_b8f25 = (jv_b8f25 * 0x14) % 0x7FFFFFFF;
              (void)jv_b8f25; }
        }
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if (((opq_63f6 * opq_63f6 - opq_63f6) % 2 == 0)) { opq_63f6_b ^= 0; }
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if (((opq_63f6 * opq_63f6 - opq_63f6) % 2 == 0)) { opq_63f6_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if ((((opq_63f6 * opq_63f6 + opq_63f6_b * opq_63f6_b) % 4) == 3)) {
        { int jv_78e02 = opq_63f6 ^ 0x9742;
            jv_78e02 = (jv_78e02 * 0x12) % 0x7FFFFFFF;
            jv_78e02 ^= (jv_78e02 << 3) | 0x7E66;
            jv_78e02 += (jv_78e02 >> 2) + 0xB9;
          (void)jv_78e02; }
    }
    printf("%d\n", found);
    return 0;
}
