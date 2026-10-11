#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x522B1F68 ^ 0x522B1F68), hi = n - (0x424D9DE4 ^ 0x424D9DE5);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x4832516F ^ 0x4832516D);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0xEC98EC2 ^ 0xEC98EC3); else hi = mid - (0x3BC9AAF4 ^ 0x3BC9AAF5);
    }
    return -(0x38E92BE8 ^ 0x38E92BE9);
}
int main(void) {
    int a[(0x64E18D76 ^ 0x64E18D66)];
    for (int i = (0xE20372 ^ 0xE20372); i < (0x5C46C7D4 ^ 0x5C46C7C4); i++) a[i] = i * (0x7E002F00 ^ 0x7E002F03) + (0x79C63BA4 ^ 0x79C63BA5);
    int found = (0x7A351E71 ^ 0x7A351E71);
    for (int k = (0x3B995969 ^ 0x3B995969); k < (0x116BE10B ^ 0x116BE139); k++) if (bsearch_idx(a, (0x7AC2A3B7 ^ 0x7AC2A3A7), k) >= (0x36E3A7DA ^ 0x36E3A7DA)) found++;
    printf("%d\n", found);
    return (0xB098189 ^ 0xB098189);
}
