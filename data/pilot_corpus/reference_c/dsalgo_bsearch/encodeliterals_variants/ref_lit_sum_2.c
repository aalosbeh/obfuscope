#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x371 - 0x371), hi = n - (0x41F - 0x41E);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x249 - 0x247);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0xB01 - 0xB00); else hi = mid - (0xFFB - 0xFFA);
    }
    return -(0x18C - 0x18B);
}
int main(void) {
    int a[(0x3D9 - 0x3C9)];
    for (int i = (0x97E - 0x97E); i < (0x92A - 0x91A); i++) a[i] = i * (0x82D - 0x82A) + (0x4A7 - 0x4A6);
    int found = (0x3AB - 0x3AB);
    for (int k = (0xDE1 - 0xDE1); k < (0x6D4 - 0x6A2); k++) if (bsearch_idx(a, (0xA74 - 0xA64), k) >= (0xA18 - 0xA18)) found++;
    printf("%d\n", found);
    return (0xA4D - 0xA4D);
}
