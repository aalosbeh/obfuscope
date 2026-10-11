#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x2948C1CC ^ 0x2948C1CC), hi = n - (0x3B1B028F ^ 0x3B1B028E);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x724F38EC ^ 0x724F38EE);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x40F5C5B8 ^ 0x40F5C5B9); else hi = mid - (0x5C505D14 ^ 0x5C505D15);
    }
    return -(0x1ECCB90A ^ 0x1ECCB90B);
}
int main(void) {
    int a[(0x4D2D9DC9 ^ 0x4D2D9DD9)];
    for (int i = (0x64702950 ^ 0x64702950); i < (0x6DF70FDC ^ 0x6DF70FCC); i++) a[i] = i * (0x310144A8 ^ 0x310144AB) + (0x3CC5B60B ^ 0x3CC5B60A);
    int found = (0x7069BE41 ^ 0x7069BE41);
    for (int k = (0x4AC427ED ^ 0x4AC427ED); k < (0x6A752FD5 ^ 0x6A752FE7); k++) if (bsearch_idx(a, (0x54623D2A ^ 0x54623D3A), k) >= (0x41610757 ^ 0x41610757)) found++;
    printf("%d\n", found);
    return (0x6E67483D ^ 0x6E67483D);
}
