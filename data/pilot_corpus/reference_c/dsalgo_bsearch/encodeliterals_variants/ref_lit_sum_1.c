#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xD79 - 0xD79), hi = n - (0xEBE - 0xEBD);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x74F - 0x74D);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x6B - 0x6A); else hi = mid - (0x286 - 0x285);
    }
    return -(0x4A8 - 0x4A7);
}
int main(void) {
    int a[(0x17A - 0x16A)];
    for (int i = (0x174 - 0x174); i < (0x5B4 - 0x5A4); i++) a[i] = i * (0x34 - 0x31) + (0x3CC - 0x3CB);
    int found = (0xE43 - 0xE43);
    for (int k = (0x708 - 0x708); k < (0xD5A - 0xD28); k++) if (bsearch_idx(a, (0xE51 - 0xE41), k) >= (0x488 - 0x488)) found++;
    printf("%d\n", found);
    return (0xF58 - 0xF58);
}
