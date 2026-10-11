#include <stdio.h>
static volatile int opq_e740 = 7;
static volatile int opq_e740_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_e740 * opq_e740 + opq_e740_b * opq_e740_b) % 4) == 3)) {
            { int jv_cfc0c = opq_e740 ^ 0x5172;
                jv_cfc0c ^= (jv_cfc0c << 3) | 0x39C7;
                jv_cfc0c = (jv_cfc0c * 0xD) % 0x7FFFFFFF;
                jv_cfc0c += (jv_cfc0c >> 2) + 0x13;
              (void)jv_cfc0c; }
        }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if ((((opq_e740 * opq_e740) % 4) == 2)) {
            { int jv_b1573 = opq_e740 ^ 0x56BB;
                jv_b1573 ^= (jv_b1573 << 3) | 0xB8BA;
              (void)jv_b1573; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_e740 * opq_e740 + opq_e740_b * opq_e740_b) % 4) == 3)) {
            { int jv_44ae1 = opq_e740 ^ 0x515B;
                jv_44ae1 ^= (jv_44ae1 << 3) | 0x4B34;
                jv_44ae1 = (jv_44ae1 * 0x20) % 0x7FFFFFFF;
                jv_44ae1 += (jv_44ae1 >> 2) + 0xAB;
              (void)jv_44ae1; }
        }
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if ((((opq_e740 * opq_e740 + opq_e740_b * opq_e740_b) % 4) == 3)) {
        { int jv_fe9a7 = opq_e740 ^ 0x9216;
            jv_fe9a7 ^= (jv_fe9a7 << 3) | 0x2B1E;
          (void)jv_fe9a7; }
    }
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if ((((opq_e740 * opq_e740 + opq_e740_b * opq_e740_b) % 4) == 3)) {
        { int jv_db42c = opq_e740 ^ 0x8BB0;
            jv_db42c += (jv_db42c >> 2) + 0x97;
            jv_db42c ^= (jv_db42c << 3) | 0xB45A;
          (void)jv_db42c; }
    }
    return 0;
}
