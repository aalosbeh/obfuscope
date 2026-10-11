#include <stdio.h>
static volatile int opq_c703 = 7;
static volatile int opq_c703_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if ((((opq_c703 * (opq_c703 + 1)) % 2) == 0)) { opq_c703_b ^= 0; }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if (((opq_c703 * opq_c703 - opq_c703) % 2 == 0)) { opq_c703_b ^= 0; }
    }
    return -1;
}
int main(void) {
    int a[16];
    if ((((opq_c703 * opq_c703 + opq_c703) % 2) == 0)) { opq_c703_b ^= 0; }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_c703 * (opq_c703 + 1)) % 2) == 0)) { opq_c703_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if (((opq_c703 * opq_c703 - opq_c703) % 2 == 0)) { opq_c703_b ^= 0; }
    printf("%d\n", found);
    return 0;
}
