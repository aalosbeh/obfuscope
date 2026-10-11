#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xCF69F7 ^ 0xCF69F7), hi = n - (0x1E46EE04 ^ 0x1E46EE05);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x10B9BB97 ^ 0x10B9BB95);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x7F726850 ^ 0x7F726851); else hi = mid - (0x790FCABD ^ 0x790FCABC);
    }
    return -(0x2852EEF7 ^ 0x2852EEF6);
}
int main(void) {
    int a[(0x70B8F21E ^ 0x70B8F20E)];
    for (int i = (0x224E9C60 ^ 0x224E9C60); i < (0x3175F485 ^ 0x3175F495); i++) a[i] = i * (0x7B9A2AE9 ^ 0x7B9A2AEA) + (0x2C8F2A53 ^ 0x2C8F2A52);
    int found = (0x78922BFB ^ 0x78922BFB);
    for (int k = (0x1659AC00 ^ 0x1659AC00); k < (0x7CBBBDE7 ^ 0x7CBBBDD5); k++) if (bsearch_idx(a, (0x2C4D4143 ^ 0x2C4D4153), k) >= (0x3DAA1ADF ^ 0x3DAA1ADF)) found++;
    printf("%d\n", found);
    return (0x376C2E24 ^ 0x376C2E24);
}
