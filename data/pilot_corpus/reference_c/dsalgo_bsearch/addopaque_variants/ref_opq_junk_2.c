#include <stdio.h>
static volatile int opq_f734 = 7;
static volatile int opq_f734_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_f734 * opq_f734) % 4) == 2)) {
        { int jv_15b6a = opq_f734 ^ 0x5DF2;
            jv_15b6a = (jv_15b6a * 0x30) % 0x7FFFFFFF;
          (void)jv_15b6a; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_f734 * opq_f734) % 4) == 2)) {
            { int jv_f4034 = opq_f734 ^ 0x94FF;
                jv_f4034 = (jv_f4034 * 0x1D) % 0x7FFFFFFF;
                jv_f4034 ^= (jv_f4034 << 3) | 0x5160;
              (void)jv_f4034; }
        }
        if (a[mid] == key) return mid;
        if ((((opq_f734 * opq_f734) % 4) == 2)) {
            { int jv_b97d1 = opq_f734 ^ 0xC237;
                jv_b97d1 ^= (jv_b97d1 << 3) | 0xD63D;
                jv_b97d1 += (jv_b97d1 >> 2) + 0x82;
              (void)jv_b97d1; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_f734 * opq_f734) % 4) == 2)) {
            { int jv_84540 = opq_f734 ^ 0x4B1C;
                jv_84540 += (jv_84540 >> 2) + 0xD;
              (void)jv_84540; }
        }
    }
    return -1;
}
int main(void) {
    int a[16];
    if ((((opq_f734 * opq_f734 + opq_f734_b * opq_f734_b) % 4) == 3)) {
        { int jv_a95ca = opq_f734 ^ 0x7D4F;
            jv_a95ca ^= (jv_a95ca << 3) | 0xD716;
          (void)jv_a95ca; }
    }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
