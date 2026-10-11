#include <stdio.h>
static volatile int opq_65ab = 7;
static volatile int opq_65ab_b = 3;

static int bsearch_idx(const int *a, int n, int key) {
    if ((((opq_65ab * opq_65ab) % 4) == 2)) {
        { int jv_90f4d = opq_65ab ^ 0xFEC3;
            jv_90f4d = (jv_90f4d * 0x3A) % 0x7FFFFFFF;
          (void)jv_90f4d; }
    }
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((((opq_65ab * opq_65ab + opq_65ab_b * opq_65ab_b) % 4) == 3)) {
            { int jv_17006 = opq_65ab ^ 0xF29B;
                jv_17006 ^= (jv_17006 << 3) | 0x6B52;
                jv_17006 += (jv_17006 >> 2) + 0x1D;
                jv_17006 = (jv_17006 * 0x25) % 0x7FFFFFFF;
              (void)jv_17006; }
        }
        if (a[mid] == key) return mid;
        if ((((opq_65ab * opq_65ab + opq_65ab_b * opq_65ab_b) % 4) == 3)) {
            { int jv_e7a70 = opq_65ab ^ 0x143D;
                jv_e7a70 ^= (jv_e7a70 << 3) | 0x3A40;
              (void)jv_e7a70; }
        }
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
        if ((((opq_65ab * opq_65ab + opq_65ab_b * opq_65ab_b) % 4) == 3)) {
            { int jv_f7dd1 = opq_65ab ^ 0x54;
                jv_f7dd1 = (jv_f7dd1 * 0x3D) % 0x7FFFFFFF;
                jv_f7dd1 += (jv_f7dd1 >> 2) + 0x29;
              (void)jv_f7dd1; }
        }
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    if ((((opq_65ab * opq_65ab) % 4) == 2)) {
        { int jv_db677 = opq_65ab ^ 0xCC06;
            jv_db677 ^= (jv_db677 << 3) | 0x7C2B;
            jv_db677 += (jv_db677 >> 2) + 0x16;
            jv_db677 = (jv_db677 * 0x26) % 0x7FFFFFFF;
          (void)jv_db677; }
    }
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf("%d\n", found);
    return 0;
}
