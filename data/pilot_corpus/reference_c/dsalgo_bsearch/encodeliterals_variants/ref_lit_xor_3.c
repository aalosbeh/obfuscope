#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x19904330 ^ 0x19904330), hi = n - (0x67390C63 ^ 0x67390C62);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x205E2EB ^ 0x205E2E9);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x2F7413F7 ^ 0x2F7413F6); else hi = mid - (0x71EA7AEB ^ 0x71EA7AEA);
    }
    return -(0x2FEC9812 ^ 0x2FEC9813);
}
int main(void) {
    int a[(0x2015BDA7 ^ 0x2015BDB7)];
    for (int i = (0x4760FEFB ^ 0x4760FEFB); i < (0x479EC8DD ^ 0x479EC8CD); i++) a[i] = i * (0x75032914 ^ 0x75032917) + (0x4914A7AE ^ 0x4914A7AF);
    int found = (0x7ADCB95D ^ 0x7ADCB95D);
    for (int k = (0x4D5EC6B9 ^ 0x4D5EC6B9); k < (0x3C54D459 ^ 0x3C54D46B); k++) if (bsearch_idx(a, (0x77E52CF ^ 0x77E52DF), k) >= (0x6ED65FFA ^ 0x6ED65FFA)) found++;
    printf("%d\n", found);
    return (0x7F076D55 ^ 0x7F076D55);
}
