#include <stdio.h>
static volatile int opq_25ad = 7;
static volatile int opq_25ad_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_25ad * (opq_25ad + 1)) % 2) == 0)) { opq_25ad_b ^= 0; }
    }
    return -1;
}
int main(void) {
    int a[16];
    if ((((opq_25ad * opq_25ad) % 4) == 2)) {
        { int jv_3f16d = opq_25ad ^ 0x49F2;
            jv_3f16d = (jv_3f16d * 0x37) % 0x7FFFFFFF;
            jv_3f16d += (jv_3f16d >> 2) + 0xD2;
          (void)jv_3f16d; }
    }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_25ad * opq_25ad + opq_25ad) % 2) == 0)) { opq_25ad_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if (((opq_25ad * opq_25ad - opq_25ad) % 2 == 0)) { opq_25ad_b ^= 0; }
    printf("%d\n", found);
    if (((opq_25ad * opq_25ad - opq_25ad) % 2 == 0)) { opq_25ad_b ^= 0; }
    return 0;
}
