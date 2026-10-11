#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x64ABE430 ^ 0x64ABE430), hi = n - (0xD58A26 ^ 0xD58A27);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x2C214C02 ^ 0x2C214C00);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x7F924799 ^ 0x7F924798); else hi = mid - (0x9A13D75 ^ 0x9A13D74);
    }
    return -(0x6601B597 ^ 0x6601B596);
}
int main(void) {
    int a[(0x43B9D481 ^ 0x43B9D491)];
    for (int i = (0x2B2E772C ^ 0x2B2E772C); i < (0xBAF0B4C ^ 0xBAF0B5C); i++) a[i] = i * (0x1B0F2017 ^ 0x1B0F2014) + (0xCFBC8E0 ^ 0xCFBC8E1);
    int found = (0x444CF33F ^ 0x444CF33F);
    for (int k = (0x7E5773E ^ 0x7E5773E); k < (0x2BDC93D6 ^ 0x2BDC93E4); k++) if (bsearch_idx(a, (0x4DEBEE3A ^ 0x4DEBEE2A), k) >= (0x6CAD47A4 ^ 0x6CAD47A4)) found++;
    printf("%d\n", found);
    return (0x530C26B1 ^ 0x530C26B1);
}
