#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xD30 - 0xD30), hi = n - (0x606 - 0x605);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0xB77 - 0xB75);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0xF9D - 0xF9C); else hi = mid - (0x1B6 - 0x1B5);
    }
    return -(0x3AF - 0x3AE);
}
int main(void) {
    int a[(0xEBF - 0xEAF)];
    for (int i = (0xED5 - 0xED5); i < (0x3E7 - 0x3D7); i++) a[i] = i * (0x5F8 - 0x5F5) + (0xBD8 - 0xBD7);
    int found = (0xAB4 - 0xAB4);
    for (int k = (0xC0A - 0xC0A); k < (0xBE2 - 0xBB0); k++) if (bsearch_idx(a, (0x5DF - 0x5CF), k) >= (0x4C7 - 0x4C7)) found++;
    printf("%d\n", found);
    return (0x4E1 - 0x4E1);
}
