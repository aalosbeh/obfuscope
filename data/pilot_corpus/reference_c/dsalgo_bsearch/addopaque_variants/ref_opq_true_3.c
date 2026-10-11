#include <stdio.h>
static volatile int opq_ced4 = 7;
static volatile int opq_ced4_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_ced4 * opq_ced4 + opq_ced4) % 2) == 0)) { opq_ced4_b ^= 0; }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if (((opq_ced4 * opq_ced4 - opq_ced4) % 2 == 0)) { opq_ced4_b ^= 0; }
    }
    return -1;
}
int main(void) {
    if ((((opq_ced4 * (opq_ced4 + 1)) % 2) == 0)) { opq_ced4_b ^= 0; }
    int a[16];
    if ((((opq_ced4 * (opq_ced4 + 1)) % 2) == 0)) { opq_ced4_b ^= 0; }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if (((opq_ced4 * opq_ced4 - opq_ced4) % 2 == 0)) { opq_ced4_b ^= 0; }
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
