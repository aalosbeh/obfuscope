#include <stdio.h>
static volatile int opq_c9f1 = 7;
static volatile int opq_c9f1_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_c9f1 * opq_c9f1) % 4) == 2)) {
        { int jv_34d02 = opq_c9f1 ^ 0x9E1C;
            jv_34d02 += (jv_34d02 >> 2) + 0x94;
          (void)jv_34d02; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_c9f1 * opq_c9f1) % 4) == 2)) {
            { int jv_7cca8 = opq_c9f1 ^ 0xCD64;
                jv_7cca8 += (jv_7cca8 >> 2) + 0x2B;
              (void)jv_7cca8; }
        }
        int mid = lo + (hi - lo) / 2;
        if ((((opq_c9f1 * opq_c9f1 + opq_c9f1) % 2) == 0)) { opq_c9f1_b ^= 0; }
        if (a[mid] == key) return mid;
        if ((((opq_c9f1 * opq_c9f1 + opq_c9f1_b * opq_c9f1_b) % 4) == 3)) {
            { int jv_71fde = opq_c9f1 ^ 0x9850;
                jv_71fde += (jv_71fde >> 2) + 0x44;
                jv_71fde = (jv_71fde * 0x20) % 0x7FFFFFFF;
              (void)jv_71fde; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if ((((opq_c9f1 * (opq_c9f1 + 1)) % 2) == 0)) { opq_c9f1_b ^= 0; }
    return 0;
}
