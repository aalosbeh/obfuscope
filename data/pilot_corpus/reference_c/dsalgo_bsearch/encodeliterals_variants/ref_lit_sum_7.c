#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x908 - 0x908), hi = n - (0x9A2 - 0x9A1);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x8DE - 0x8DC);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x22E - 0x22D); else hi = mid - (0xE27 - 0xE26);
    }
    return -(0x282 - 0x281);
}
int main(void) {
    int a[(0x9E3 - 0x9D3)];
    for (int i = (0xC5F - 0xC5F); i < (0x6B8 - 0x6A8); i++) a[i] = i * (0xA5B - 0xA58) + (0x169 - 0x168);
    int found = (0xB9 - 0xB9);
    for (int k = (0x24D - 0x24D); k < (0xB08 - 0xAD6); k++) if (bsearch_idx(a, (0xB04 - 0xAF4), k) >= (0x246 - 0x246)) found++;
    printf("%d\n", found);
    return (0xF57 - 0xF57);
}
