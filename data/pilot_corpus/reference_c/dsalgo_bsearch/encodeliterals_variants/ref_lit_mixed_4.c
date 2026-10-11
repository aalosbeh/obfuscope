#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x4C34EAF8 ^ 0x4C34EAF8), hi = n - (0x112D47B3 ^ 0x112D47B2);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x4890E091 ^ 0x4890E093);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x424 - 0x423); else hi = mid - (0x708 - 0x707);
    }
    return -(0x4641310C ^ 0x4641310D);
}
int main(void) {
    int a[(0x2E198DF1 ^ 0x2E198DE1)];
    for (int i = (0x25D - 0x25D); i < (0x714 - 0x704); i++) a[i] = i * (0x6FAD6B59 ^ 0x6FAD6B5A) + (0x4433E48F ^ 0x4433E48E);
    int found = (0x6D3 - 0x6D3);
    for (int k = (0x35EE9738 ^ 0x35EE9738); k < (0x190D0B35 ^ 0x190D0B07); k++) if (bsearch_idx(a, (0x44E05A99 ^ 0x44E05A89), k) >= (0x102305B0 ^ 0x102305B0)) found++;
    printf("%d\n", found);
    return (0x8D0 - 0x8D0);
}
