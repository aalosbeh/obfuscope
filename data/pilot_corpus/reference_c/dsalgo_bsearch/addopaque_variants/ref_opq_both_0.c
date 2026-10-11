#include <stdio.h>
static volatile int opq_afde = 7;
static volatile int opq_afde_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_afde * (opq_afde + 1)) % 2) == 0)) { opq_afde_b ^= 0; }
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    if ((((opq_afde * opq_afde + opq_afde_b * opq_afde_b) % 4) == 3)) {
        { int jv_3bb5e = opq_afde ^ 0x547A;
            jv_3bb5e = (jv_3bb5e * 0x1E) % 0x7FFFFFFF;
            jv_3bb5e += (jv_3bb5e >> 2) + 0xD5;
            jv_3bb5e ^= (jv_3bb5e << 3) | 0xB88C;
          (void)jv_3bb5e; }
    }
    int a[16];
    if (((opq_afde * opq_afde - opq_afde) % 2 == 0)) { opq_afde_b ^= 0; }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_afde * (opq_afde + 1)) % 2) == 0)) { opq_afde_b ^= 0; }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if ((((opq_afde * (opq_afde + 1)) % 2) == 0)) { opq_afde_b ^= 0; }
    return 0;
}
