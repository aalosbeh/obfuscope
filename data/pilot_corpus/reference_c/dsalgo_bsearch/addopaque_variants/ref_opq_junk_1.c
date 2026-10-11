#include <stdio.h>
static volatile int opq_b4f7 = 7;
static volatile int opq_b4f7_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_b4f7 * opq_b4f7 + opq_b4f7_b * opq_b4f7_b) % 4) == 3)) {
        { int jv_e9f56 = opq_b4f7 ^ 0xC44A;
            jv_e9f56 += (jv_e9f56 >> 2) + 0xDE;
          (void)jv_e9f56; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_b4f7 * opq_b4f7 + opq_b4f7_b * opq_b4f7_b) % 4) == 3)) {
            { int jv_15cc2 = opq_b4f7 ^ 0x7D53;
                jv_15cc2 = (jv_15cc2 * 0x36) % 0x7FFFFFFF;
                jv_15cc2 += (jv_15cc2 >> 2) + 0x99;
                jv_15cc2 ^= (jv_15cc2 << 3) | 0x266D;
              (void)jv_15cc2; }
        }
    }
    return -1;
}
int main(void) {
    int a[16];
    if ((((opq_b4f7 * opq_b4f7) % 4) == 2)) {
        { int jv_5758e = opq_b4f7 ^ 0x5EA5;
            jv_5758e ^= (jv_5758e << 3) | 0x9975;
            jv_5758e = (jv_5758e * 0x9) % 0x7FFFFFFF;
            jv_5758e += (jv_5758e >> 2) + 0x77;
          (void)jv_5758e; }
    }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_b4f7 * opq_b4f7 + opq_b4f7_b * opq_b4f7_b) % 4) == 3)) {
        { int jv_66656 = opq_b4f7 ^ 0xD215;
            jv_66656 += (jv_66656 >> 2) + 0x8C;
            jv_66656 ^= (jv_66656 << 3) | 0xA6B3;
            jv_66656 = (jv_66656 * 0x3A) % 0x7FFFFFFF;
          (void)jv_66656; }
    }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    if ((((opq_b4f7 * opq_b4f7 + opq_b4f7_b * opq_b4f7_b) % 4) == 3)) {
        { int jv_9d1b2 = opq_b4f7 ^ 0xC4EF;
            jv_9d1b2 = (jv_9d1b2 * 0x6) % 0x7FFFFFFF;
          (void)jv_9d1b2; }
    }
    printf("%d\n", found);
    return 0;
}
