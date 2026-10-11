#include <stdio.h>
static volatile int opq_11ec = 7;
static volatile int opq_11ec_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_11ec * opq_11ec + opq_11ec) % 2) == 0)) { opq_11ec_b ^= 0; }
    }
    return -1;
}
int main(void) {
    if ((((opq_11ec * opq_11ec + opq_11ec_b * opq_11ec_b) % 4) == 3)) {
        { int jv_69bb1 = opq_11ec ^ 0x67B0;
            jv_69bb1 += (jv_69bb1 >> 2) + 0xBF;
            jv_69bb1 = (jv_69bb1 * 0x1A) % 0x7FFFFFFF;
          (void)jv_69bb1; }
    }
    int a[16];
    if ((((opq_11ec * opq_11ec + opq_11ec) % 2) == 0)) { opq_11ec_b ^= 0; }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if ((((opq_11ec * opq_11ec + opq_11ec) % 2) == 0)) { opq_11ec_b ^= 0; }
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if ((((opq_11ec * (opq_11ec + 1)) % 2) == 0)) { opq_11ec_b ^= 0; }
    printf("%d\n", found);
    return 0;
}
