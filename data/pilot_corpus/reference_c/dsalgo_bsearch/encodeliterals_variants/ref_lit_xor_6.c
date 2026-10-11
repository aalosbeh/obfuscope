#include <stdio.h>
static int bsearch_idx(const int *a, int n, int key) {
    int lo = (0x7DF186CB ^ 0x7DF186CB), hi = n - (0x34AB354F ^ 0x34AB354E);
    while (lo <= hi) {
        int mid = lo + (hi - lo) / (0x559ED68A ^ 0x559ED688);
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + (0x7CE9F1D6 ^ 0x7CE9F1D7); else hi = mid - (0x12199BA6 ^ 0x12199BA7);
    }
    return -(0x702668E5 ^ 0x702668E4);
}
int main(void) {
    int a[(0x31ED8243 ^ 0x31ED8253)];
    for (int i = (0x21A45CF4 ^ 0x21A45CF4); i < (0x5B3F0CFD ^ 0x5B3F0CED); i++) a[i] = i * (0x6D13F5C6 ^ 0x6D13F5C5) + (0x14F0A592 ^ 0x14F0A593);
    int found = (0x7A0C19F5 ^ 0x7A0C19F5);
    for (int k = (0x464E0D97 ^ 0x464E0D97); k < (0x14577F97 ^ 0x14577FA5); k++) if (bsearch_idx(a, (0x3FAF3FBD ^ 0x3FAF3FAD), k) >= (0x12D48B7E ^ 0x12D48B7E)) found++;
    printf("%d\n", found);
    return (0x3919BBF6 ^ 0x3919BBF6);
}
