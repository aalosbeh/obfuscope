#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x204 - 0x204), hi = n - (0x230 - 0x22F);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0xA2E - 0xA2C);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x83F - 0x83E); else hi = mid - (0xB37 - 0xB36);
    }
    return -(0x1C7 - 0x1C6);
}
int main(void) {
    int a[(0x75B - 0x74B)];
    for (int i = (0x5A8 - 0x5A8); i < (0xACF - 0xABF); i++) a[i] = i * (0xE35 - 0xE32) + (0xB64 - 0xB63);
    int found = (0x6D3 - 0x6D3);
    for (int k = (0xF1C - 0xF1C); k < (0x87B - 0x849); k++) if (bsearch_idx(a, (0x4B1 - 0x4A1), k) >= (0xBCF - 0xBCF)) found++;
    printf("%d\n", found);
    return (0x238 - 0x238);
}
