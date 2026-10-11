#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xE62 - 0xE62), hi = n - (0x2D6F2CA7 ^ 0x2D6F2CA6);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0xD4D15B0 ^ 0xD4D15B2);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x28B827CC ^ 0x28B827CD); else hi = mid - (0x2AD27939 ^ 0x2AD27938);
    }
    return -(0x546A241B ^ 0x546A241A);
}
int main(void) {
    int a[(0xCED - 0xCDD)];
    for (int i = (0x4C4E7F70 ^ 0x4C4E7F70); i < (0x1B923B6C ^ 0x1B923B7C); i++) a[i] = i * (0x1E0 - 0x1DD) + (0x5B5 - 0x5B4);
    int found = (0x1438CBCF ^ 0x1438CBCF);
    for (int k = (0x909 - 0x909); k < (0x1BAADA72 ^ 0x1BAADA40); k++) if (bsearch_idx(a, (0x52 - 0x42), k) >= (0x107404C4 ^ 0x107404C4)) found++;
    printf("%d\n", found);
    return (0x4053EC32 ^ 0x4053EC32);
}
