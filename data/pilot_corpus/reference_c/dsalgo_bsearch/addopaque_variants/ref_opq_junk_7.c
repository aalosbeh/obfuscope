#include <stdio.h>
static volatile int opq_6015 = 7;
static volatile int opq_6015_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_6015 * opq_6015) % 4) == 2)) {
        { int jv_ca5ac = opq_6015 ^ 0x77A6;
            jv_ca5ac = (jv_ca5ac * 0x25) % 0x7FFFFFFF;
            jv_ca5ac ^= (jv_ca5ac << 3) | 0x3E3C;
            jv_ca5ac += (jv_ca5ac >> 2) + 0xD;
          (void)jv_ca5ac; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        if ((((opq_6015 * opq_6015 + opq_6015_b * opq_6015_b) % 4) == 3)) {
            { int jv_94cbd = opq_6015 ^ 0xB6A5;
                jv_94cbd = (jv_94cbd * 0x24) % 0x7FFFFFFF;
                jv_94cbd ^= (jv_94cbd << 3) | 0x9DC9;
              (void)jv_94cbd; }
        }
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if ((((opq_6015 * opq_6015) % 4) == 2)) {
            { int jv_93609 = opq_6015 ^ 0x1545;
                jv_93609 ^= (jv_93609 << 3) | 0x2F6A;
                jv_93609 += (jv_93609 >> 2) + 0x57;
              (void)jv_93609; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    if ((((opq_6015 * opq_6015 + opq_6015_b * opq_6015_b) % 4) == 3)) {
        { int jv_22705 = opq_6015 ^ 0x7E52;
            jv_22705 += (jv_22705 >> 2) + 0x8A;
          (void)jv_22705; }
    }
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    if ((((opq_6015 * opq_6015) % 4) == 2)) {
        { int jv_8bcc2 = opq_6015 ^ 0xDF13;
            jv_8bcc2 ^= (jv_8bcc2 << 3) | 0x7354;
          (void)jv_8bcc2; }
    }
    return 0;
}
