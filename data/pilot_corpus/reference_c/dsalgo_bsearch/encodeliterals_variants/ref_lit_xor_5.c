#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x3395DA2A ^ 0x3395DA2A), hi = n - (0xA616B8D ^ 0xA616B8C);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x678A50D2 ^ 0x678A50D0);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x7C649E72 ^ 0x7C649E73); else hi = mid - (0x5F6A72CD ^ 0x5F6A72CC);
    }
    return -(0x5A790505 ^ 0x5A790504);
}
int main(void) {
    int a[(0x3B374D3 ^ 0x3B374C3)];
    for (int i = (0x1A5FF447 ^ 0x1A5FF447); i < (0x539AF751 ^ 0x539AF741); i++) a[i] = i * (0x3D1D4CB8 ^ 0x3D1D4CBB) + (0x6A633E91 ^ 0x6A633E90);
    int found = (0x2CBB99AF ^ 0x2CBB99AF);
    for (int k = (0x4114539C ^ 0x4114539C); k < (0x4C5278DB ^ 0x4C5278E9); k++) if (bsearch_idx(a, (0x5310EAA2 ^ 0x5310EAB2), k) >= (0x5E70DE39 ^ 0x5E70DE39)) found++;
    printf("%d\n", found);
    return (0x2821651C ^ 0x2821651C);
}
