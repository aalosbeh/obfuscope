#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x44FC249C ^ 0x44FC249C), hi = n - (0x6B20DA81 ^ 0x6B20DA80);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0xB23 - 0xB21);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x2BA - 0x2B9); else hi = mid - (0x3957E04F ^ 0x3957E04E);
    }
    return -(0x6B5E89E7 ^ 0x6B5E89E6);
}
int main(void) {
    int a[(0x45ACDE8 ^ 0x45ACDF8)];
    for (int i = (0x734B474B ^ 0x734B474B); i < (0x19BF487A ^ 0x19BF486A); i++) a[i] = i * (0x3B470551 ^ 0x3B470552) + (0x8B0 - 0x8AF);
    int found = (0xD7C - 0xD7C);
    for (int k = (0x1EB - 0x1EB); k < (0x990 - 0x95E); k++) if (bsearch_idx(a, (0xBB1 - 0xBA1), k) >= (0x70509409 ^ 0x70509409)) found++;
    printf("%d\n", found);
    return (0x41F66DC4 ^ 0x41F66DC4);
}
