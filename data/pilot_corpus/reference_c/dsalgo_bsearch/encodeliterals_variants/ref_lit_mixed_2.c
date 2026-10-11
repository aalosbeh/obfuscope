#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xCA6 - 0xCA6), hi = n - (0x79B - 0x79A);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x62306822 ^ 0x62306820);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x57AFFFDC ^ 0x57AFFFDD); else hi = mid - (0x2DF - 0x2DE);
    }
    return -(0x64174B28 ^ 0x64174B29);
}
int main(void) {
    int a[(0x1E2810B1 ^ 0x1E2810A1)];
    for (int i = (0x824 - 0x824); i < (0x2F4 - 0x2E4); i++) a[i] = i * (0x7FCB65D7 ^ 0x7FCB65D4) + (0x748CDCB1 ^ 0x748CDCB0);
    int found = (0x1B16A19F ^ 0x1B16A19F);
    for (int k = (0x1BDFABB6 ^ 0x1BDFABB6); k < (0x533 - 0x501); k++) if (bsearch_idx(a, (0x47D9DD84 ^ 0x47D9DD94), k) >= (0xB464669 ^ 0xB464669)) found++;
    printf("%d\n", found);
    return (0x9CA - 0x9CA);
}
