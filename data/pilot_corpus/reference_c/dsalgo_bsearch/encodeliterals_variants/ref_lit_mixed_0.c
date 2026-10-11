#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x383 - 0x383), hi = n - (0x7FE - 0x7FD);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x1AEC249A ^ 0x1AEC2498);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x591 - 0x590); else hi = mid - (0x1B7AD85A ^ 0x1B7AD85B);
    }
    return -(0x75D6105B ^ 0x75D6105A);
}
int main(void) {
    int a[(0x623 - 0x613)];
    for (int i = (0x344C8194 ^ 0x344C8194); i < (0x609B1156 ^ 0x609B1146); i++) a[i] = i * (0x72F408C4 ^ 0x72F408C7) + (0x22F - 0x22E);
    int found = (0x72DCEE00 ^ 0x72DCEE00);
    for (int k = (0x31DB65B1 ^ 0x31DB65B1); k < (0x7B923C1B ^ 0x7B923C29); k++) if (bsearch_idx(a, (0x400 - 0x3F0), k) >= (0x6DD - 0x6DD)) found++;
    printf("%d\n", found);
    return (0xB7C - 0xB7C);
}
