#include <stdio.h>
static volatile int opq_9489 = 7;
static volatile int opq_9489_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_9489 * opq_9489) % 4) == 2)) {
            { int jv_83495 = opq_9489 ^ 0x4CD7;
                jv_83495 = (jv_83495 * 0xE) % 0x7FFFFFFF;
              (void)jv_83495; }
        }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    if ((((opq_9489 * opq_9489 + opq_9489_b * opq_9489_b) % 4) == 3)) {
        { int jv_381f2 = opq_9489 ^ 0xF7C2;
            jv_381f2 ^= (jv_381f2 << 3) | 0xF798;
            jv_381f2 += (jv_381f2 >> 2) + 0xDE;
            jv_381f2 = (jv_381f2 * 0x37) % 0x7FFFFFFF;
          (void)jv_381f2; }
    }
    int a[16];
    if ((((opq_9489 * opq_9489) % 4) == 2)) {
        { int jv_93189 = opq_9489 ^ 0xBCCE;
            jv_93189 = (jv_93189 * 0x1F) % 0x7FFFFFFF;
            jv_93189 ^= (jv_93189 << 3) | 0xBCFC;
            jv_93189 += (jv_93189 >> 2) + 0xB0;
          (void)jv_93189; }
    }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if ((((opq_9489 * opq_9489) % 4) == 2)) {
        { int jv_456d6 = opq_9489 ^ 0x833C;
            jv_456d6 = (jv_456d6 * 0x9) % 0x7FFFFFFF;
            jv_456d6 += (jv_456d6 >> 2) + 0x4D;
          (void)jv_456d6; }
    }
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if ((((opq_9489 * opq_9489 + opq_9489_b * opq_9489_b) % 4) == 3)) {
        { int jv_4bfd1 = opq_9489 ^ 0x584A;
            jv_4bfd1 += (jv_4bfd1 >> 2) + 0x9;
            jv_4bfd1 = (jv_4bfd1 * 0x35) % 0x7FFFFFFF;
            jv_4bfd1 ^= (jv_4bfd1 << 3) | 0xAC8F;
          (void)jv_4bfd1; }
    }
    return 0;
}
