#include <stdio.h>
static volatile int opq_aa57 = 7;
static volatile int opq_aa57_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_aa57 * (opq_aa57 + 1)) % 2) == 0)) { opq_aa57_b ^= 0; }
        if (a[mid] == key) return mid;
        if ((((opq_aa57 * opq_aa57 + opq_aa57_b * opq_aa57_b) % 4) == 3)) {
            { int jv_4f6c2 = opq_aa57 ^ 0x576;
                jv_4f6c2 = (jv_4f6c2 * 0x3B) % 0x7FFFFFFF;
                jv_4f6c2 += (jv_4f6c2 >> 2) + 0x56;
              (void)jv_4f6c2; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    if (((opq_aa57 * opq_aa57 - opq_aa57) % 2 == 0)) { opq_aa57_b ^= 0; }
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if ((((opq_aa57 * opq_aa57 + opq_aa57_b * opq_aa57_b) % 4) == 3)) {
        { int jv_c8a78 = opq_aa57 ^ 0xDF99;
            jv_c8a78 += (jv_c8a78 >> 2) + 0x4;
          (void)jv_c8a78; }
    }
    int found = 0;
    if ((((opq_aa57 * (opq_aa57 + 1)) % 2) == 0)) { opq_aa57_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
