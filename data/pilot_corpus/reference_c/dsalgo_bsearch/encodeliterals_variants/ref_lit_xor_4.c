#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x2E4E0699 ^ 0x2E4E0699), hi = n - (0x38DC30B0 ^ 0x38DC30B1);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x5B6C05DF ^ 0x5B6C05DD);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x2FA4B022 ^ 0x2FA4B023); else hi = mid - (0xB5B344B ^ 0xB5B344A);
    }
    return -(0x50D2C5A1 ^ 0x50D2C5A0);
}
int main(void) {
    int a[(0x36C18C45 ^ 0x36C18C55)];
    for (int i = (0x306D75B2 ^ 0x306D75B2); i < (0x2406D23E ^ 0x2406D22E); i++) a[i] = i * (0x5F81EC77 ^ 0x5F81EC74) + (0x5F0DF5AA ^ 0x5F0DF5AB);
    int found = (0x5E358102 ^ 0x5E358102);
    for (int k = (0x2BF3B8F ^ 0x2BF3B8F); k < (0x2995A0BA ^ 0x2995A088); k++) if (bsearch_idx(a, (0x5CF76EB3 ^ 0x5CF76EA3), k) >= (0x5B4B1A0E ^ 0x5B4B1A0E)) found++;
    printf("%d\n", found);
    return (0xDF33CBB ^ 0xDF33CBB);
}
