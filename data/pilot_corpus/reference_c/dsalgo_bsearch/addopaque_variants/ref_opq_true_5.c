#include <stdio.h>
static volatile int opq_1a6d = 7;
static volatile int opq_1a6d_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if (((opq_1a6d * opq_1a6d - opq_1a6d) % 2 == 0)) { opq_1a6d_b ^= 0; }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_1a6d * opq_1a6d + opq_1a6d) % 2) == 0)) { opq_1a6d_b ^= 0; }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    if ((((opq_1a6d * opq_1a6d + opq_1a6d) % 2) == 0)) { opq_1a6d_b ^= 0; }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_1a6d * (opq_1a6d + 1)) % 2) == 0)) { opq_1a6d_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if (((opq_1a6d * opq_1a6d - opq_1a6d) % 2 == 0)) { opq_1a6d_b ^= 0; }
    return 0;
}
