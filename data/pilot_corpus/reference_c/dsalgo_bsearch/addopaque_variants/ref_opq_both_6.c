#include <stdio.h>
static volatile int opq_cead = 7;
static volatile int opq_cead_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_cead * opq_cead) % 4) == 2)) {
            { int jv_6b78d = opq_cead ^ 0x7F5A;
                jv_6b78d = (jv_6b78d * 0x3C) % 0x7FFFFFFF;
                jv_6b78d ^= (jv_6b78d << 3) | 0x2119;
                jv_6b78d += (jv_6b78d >> 2) + 0x67;
              (void)jv_6b78d; }
        }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if ((((opq_cead * (opq_cead + 1)) % 2) == 0)) { opq_cead_b ^= 0; }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_cead * (opq_cead + 1)) % 2) == 0)) { opq_cead_b ^= 0; }
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if ((((opq_cead * opq_cead) % 4) == 2)) {
        { int jv_83b99 = opq_cead ^ 0x52B;
            jv_83b99 = (jv_83b99 * 0x34) % 0x7FFFFFFF;
            jv_83b99 += (jv_83b99 >> 2) + 0xE;
          (void)jv_83b99; }
    }
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if ((((opq_cead * opq_cead) % 4) == 2)) {
        { int jv_43317 = opq_cead ^ 0xBB85;
            jv_43317 ^= (jv_43317 << 3) | 0xB129;
          (void)jv_43317; }
    }
    printf("%d\n", found);
    return 0;
}
