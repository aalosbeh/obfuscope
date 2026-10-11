#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xB5F - 0xB5F), hi = n - (0x7D3949B2 ^ 0x7D3949B3);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x7F3D5490 ^ 0x7F3D5492);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x351A3BB1 ^ 0x351A3BB0); else hi = mid - (0x12537AB9 ^ 0x12537AB8);
    }
    return -(0x35B05725 ^ 0x35B05724);
}
int main(void) {
    int a[(0x4727D29A ^ 0x4727D28A)];
    for (int i = (0xF30 - 0xF30); i < (0x5AB - 0x59B); i++) a[i] = i * (0x7B8 - 0x7B5) + (0x4F22E297 ^ 0x4F22E296);
    int found = (0x6B3 - 0x6B3);
    for (int k = (0x3DDC6652 ^ 0x3DDC6652); k < (0x29F1D94A ^ 0x29F1D978); k++) if (bsearch_idx(a, (0x604 - 0x5F4), k) >= (0x706 - 0x706)) found++;
    printf("%d\n", found);
    return (0xB837CFE ^ 0xB837CFE);
}
