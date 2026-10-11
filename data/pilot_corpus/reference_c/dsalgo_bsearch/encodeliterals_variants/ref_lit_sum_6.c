#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xEEA - 0xEEA), hi = n - (0x489 - 0x488);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0xEA - 0xE8);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x836 - 0x835); else hi = mid - (0xF9C - 0xF9B);
    }
    return -(0x6B0 - 0x6AF);
}
int main(void) {
    int a[(0x79A - 0x78A)];
    for (int i = (0x187 - 0x187); i < (0x193 - 0x183); i++) a[i] = i * (0x1F5 - 0x1F2) + (0x4D2 - 0x4D1);
    int found = (0xC94 - 0xC94);
    for (int k = (0x294 - 0x294); k < (0x91C - 0x8EA); k++) if (bsearch_idx(a, (0x7C2 - 0x7B2), k) >= (0x9E8 - 0x9E8)) found++;
    printf("%d\n", found);
    return (0x998 - 0x998);
}
