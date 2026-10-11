#include <stdio.h>
static volatile int opq_4873 = 7;
static volatile int opq_4873_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_4873 * opq_4873 + opq_4873_b * opq_4873_b) % 4) == 3)) {
        { int jv_91d1d = opq_4873 ^ 0xE649;
            jv_91d1d += (jv_91d1d >> 2) + 0xA5;
            jv_91d1d = (jv_91d1d * 0x35) % 0x7FFFFFFF;
          (void)jv_91d1d; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_4873 * opq_4873 + opq_4873_b * opq_4873_b) % 4) == 3)) {
            { int jv_90de2 = opq_4873 ^ 0x4B00;
                jv_90de2 ^= (jv_90de2 << 3) | 0xD6E5;
                jv_90de2 += (jv_90de2 >> 2) + 0x86;
              (void)jv_90de2; }
        }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if ((((opq_4873 * opq_4873 + opq_4873_b * opq_4873_b) % 4) == 3)) {
            { int jv_7c1dd = opq_4873 ^ 0xB4A2;
                jv_7c1dd += (jv_7c1dd >> 2) + 0xA1;
              (void)jv_7c1dd; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    if ((((opq_4873 * opq_4873 + opq_4873_b * opq_4873_b) % 4) == 3)) {
        { int jv_5672f = opq_4873 ^ 0xD6D8;
            jv_5672f ^= (jv_5672f << 3) | 0xC7B;
            jv_5672f += (jv_5672f >> 2) + 0xFA;
          (void)jv_5672f; }
    }
    int a[16];
    if ((((opq_4873 * opq_4873) % 4) == 2)) {
        { int jv_897f4 = opq_4873 ^ 0xD1B2;
            jv_897f4 += (jv_897f4 >> 2) + 0xF3;
          (void)jv_897f4; }
    }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
