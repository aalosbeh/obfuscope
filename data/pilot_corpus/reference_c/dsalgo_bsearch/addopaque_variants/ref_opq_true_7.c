#include <stdio.h>
static volatile int opq_9f2d = 7;
static volatile int opq_9f2d_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_9f2d * (opq_9f2d + 1)) % 2) == 0)) { opq_9f2d_b ^= 0; }
        int mid = lo + (hi - lo) / 2;
        if ((((opq_9f2d * opq_9f2d + opq_9f2d) % 2) == 0)) { opq_9f2d_b ^= 0; }
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_9f2d * (opq_9f2d + 1)) % 2) == 0)) { opq_9f2d_b ^= 0; }
    }
    return -1;
}
int main(void) {
    if ((((opq_9f2d * opq_9f2d + opq_9f2d) % 2) == 0)) { opq_9f2d_b ^= 0; }
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_9f2d * opq_9f2d + opq_9f2d) % 2) == 0)) { opq_9f2d_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
