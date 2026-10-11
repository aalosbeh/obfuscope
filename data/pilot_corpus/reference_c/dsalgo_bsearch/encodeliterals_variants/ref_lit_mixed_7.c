#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xECE - 0xECE), hi = n - (0x96ABEDD ^ 0x96ABEDC);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x747 - 0x745);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x501 - 0x500); else hi = mid - (0x429 - 0x428);
    }
    return -(0x722 - 0x721);
}
int main(void) {
    int a[(0x45330DAB ^ 0x45330DBB)];
    for (int i = (0xCF8 - 0xCF8); i < (0x146DE841 ^ 0x146DE851); i++) a[i] = i * (0xE87 - 0xE84) + (0x4B3986E4 ^ 0x4B3986E5);
    int found = (0x634018C4 ^ 0x634018C4);
    for (int k = (0x4A5 - 0x4A5); k < (0xE92 - 0xE60); k++) if (bsearch_idx(a, (0xB28 - 0xB18), k) >= (0x1E4CE0EA ^ 0x1E4CE0EA)) found++;
    printf("%d\n", found);
    return (0x8AC - 0x8AC);
}
