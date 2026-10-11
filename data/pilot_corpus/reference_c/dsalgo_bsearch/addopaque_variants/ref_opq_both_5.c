#include <stdio.h>
static volatile int opq_28a7 = 7;
static volatile int opq_28a7_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_28a7 * opq_28a7) % 4) == 2)) {
            { int jv_44c93 = opq_28a7 ^ 0xEA71;
                jv_44c93 = (jv_44c93 * 0x17) % 0x7FFFFFFF;
              (void)jv_44c93; }
        }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if ((((opq_28a7 * opq_28a7) % 4) == 2)) {
            { int jv_b4d6b = opq_28a7 ^ 0x4BC;
                jv_b4d6b ^= (jv_b4d6b << 3) | 0x14F1;
                jv_b4d6b = (jv_b4d6b * 0x30) % 0x7FFFFFFF;
              (void)jv_b4d6b; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_28a7 * (opq_28a7 + 1)) % 2) == 0)) { opq_28a7_b ^= 0; }
    }
    return -1;
}
int main(void) {
    if ((((opq_28a7 * opq_28a7) % 4) == 2)) {
        { int jv_a34ba = opq_28a7 ^ 0x16C1;
            jv_a34ba += (jv_a34ba >> 2) + 0x2E;
          (void)jv_a34ba; }
    }
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if (((opq_28a7 * opq_28a7 - opq_28a7) % 2 == 0)) { opq_28a7_b ^= 0; }
    return 0;
}
