#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x5F1 - 0x5F1), hi = n - (0x5C0715A1 ^ 0x5C0715A0);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x722A6795 ^ 0x722A6797);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x60B33012 ^ 0x60B33013); else hi = mid - (0x5296AD0D ^ 0x5296AD0C);
    }
    return -(0x342 - 0x341);
}
int main(void) {
    int a[(0x6DF - 0x6CF)];
    for (int i = (0xA9D - 0xA9D); i < (0x6A103061 ^ 0x6A103071); i++) a[i] = i * (0x11F80ADA ^ 0x11F80AD9) + (0x27FC63FD ^ 0x27FC63FC);
    int found = (0x684EF278 ^ 0x684EF278);
    for (int k = (0xF715851 ^ 0xF715851); k < (0xC38 - 0xC06); k++) if (bsearch_idx(a, (0x7EC - 0x7DC), k) >= (0x26A - 0x26A)) found++;
    printf("%d\n", found);
    return (0x3528FDB2 ^ 0x3528FDB2);
}
