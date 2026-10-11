#include <stdio.h>
static volatile int opq_99f3 = 7;
static volatile int opq_99f3_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_99f3 * opq_99f3) % 4) == 2)) {
        { int jv_7e753 = opq_99f3 ^ 0x24BC;
            jv_7e753 ^= (jv_7e753 << 3) | 0xDC83;
          (void)jv_7e753; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_99f3 * opq_99f3 + opq_99f3_b * opq_99f3_b) % 4) == 3)) {
            { int jv_f2b4b = opq_99f3 ^ 0xA69C;
                jv_f2b4b += (jv_f2b4b >> 2) + 0x12;
                jv_f2b4b = (jv_f2b4b * 0x2C) % 0x7FFFFFFF;
              (void)jv_f2b4b; }
        }
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_99f3 * opq_99f3) % 4) == 2)) {
            { int jv_385ed = opq_99f3 ^ 0x57EA;
                jv_385ed += (jv_385ed >> 2) + 0x18;
                jv_385ed = (jv_385ed * 0x25) % 0x7FFFFFFF;
                jv_385ed ^= (jv_385ed << 3) | 0x143E;
              (void)jv_385ed; }
        }
    }
    return -1;
}
int main(void) {
    if ((((opq_99f3 * opq_99f3 + opq_99f3_b * opq_99f3_b) % 4) == 3)) {
        { int jv_77591 = opq_99f3 ^ 0xD595;
            jv_77591 ^= (jv_77591 << 3) | 0xA36F;
            jv_77591 += (jv_77591 >> 2) + 0x4;
          (void)jv_77591; }
    }
    int a[16];
    if ((((opq_99f3 * opq_99f3 + opq_99f3_b * opq_99f3_b) % 4) == 3)) {
        { int jv_11beb = opq_99f3 ^ 0x424E;
            jv_11beb ^= (jv_11beb << 3) | 0xA2CA;
            jv_11beb = (jv_11beb * 0x38) % 0x7FFFFFFF;
            jv_11beb += (jv_11beb >> 2) + 0x7F;
          (void)jv_11beb; }
    }
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
