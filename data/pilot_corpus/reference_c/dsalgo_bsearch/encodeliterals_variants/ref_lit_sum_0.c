#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0xAC - 0xAC), hi = n - (0xA8F - 0xA8E);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0xEB - 0xE9);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x869 - 0x868); else hi = mid - (0xA2 - 0xA1);
    }
    return -(0x559 - 0x558);
}
int main(void) {
    int a[(0x232 - 0x222)];
    for (int i = (0xF28 - 0xF28); i < (0x1A6 - 0x196); i++) a[i] = i * (0x8BC - 0x8B9) + (0x2E9 - 0x2E8);
    int found = (0x8E8 - 0x8E8);
    for (int k = (0x538 - 0x538); k < (0xAEC - 0xABA); k++) if (bsearch_idx(a, (0xD83 - 0xD73), k) >= (0xF1E - 0xF1E)) found++;
    printf("%d\n", found);
    return (0x33A - 0x33A);
}
