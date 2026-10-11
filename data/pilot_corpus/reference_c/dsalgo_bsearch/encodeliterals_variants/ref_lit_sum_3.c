#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x8B3 - 0x8B3), hi = n - (0x641 - 0x640);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x771 - 0x76F);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x4E7 - 0x4E6); else hi = mid - (0x3DA - 0x3D9);
    }
    return -(0xC84 - 0xC83);
}
int main(void) {
    int a[(0xB2E - 0xB1E)];
    for (int i = (0x1EE - 0x1EE); i < (0x32C - 0x31C); i++) a[i] = i * (0x337 - 0x334) + (0x8EE - 0x8ED);
    int found = (0x652 - 0x652);
    for (int k = (0x16D - 0x16D); k < (0x720 - 0x6EE); k++) if (bsearch_idx(a, (0x76D - 0x75D), k) >= (0xDB8 - 0xDB8)) found++;
    printf("%d\n", found);
    return (0x2FC - 0x2FC);
}
