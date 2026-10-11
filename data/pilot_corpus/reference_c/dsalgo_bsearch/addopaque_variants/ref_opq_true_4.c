#include <stdio.h>
static volatile int opq_5353 = 7;
static volatile int opq_5353_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_5353 * (opq_5353 + 1)) % 2) == 0)) { opq_5353_b ^= 0; }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_5353 * opq_5353 + opq_5353) % 2) == 0)) { opq_5353_b ^= 0; }
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if (((opq_5353 * opq_5353 - opq_5353) % 2 == 0)) { opq_5353_b ^= 0; }
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if (((opq_5353 * opq_5353 - opq_5353) % 2 == 0)) { opq_5353_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if ((((opq_5353 * opq_5353 + opq_5353) % 2) == 0)) { opq_5353_b ^= 0; }
    printf("%d\n", found);
    return 0;
}
