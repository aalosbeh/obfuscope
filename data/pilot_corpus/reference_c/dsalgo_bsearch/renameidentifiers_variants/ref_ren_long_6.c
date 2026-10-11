#include <stdio.h>
static int bsearch_idx(const int *a, int n, int goqdtwidvtjmqgapqgxtv) {
    int ugeclixcbejznjnts = 0, hi = n - 1;
    while (ugeclixcbejznjnts <= hi) {
        int pwknwgdtsgxrklugaydksw = ugeclixcbejznjnts + (hi - ugeclixcbejznjnts) / 2;
        if (a[pwknwgdtsgxrklugaydksw] == goqdtwidvtjmqgapqgxtv) return pwknwgdtsgxrklugaydksw;
        if (a[pwknwgdtsgxrklugaydksw] < goqdtwidvtjmqgapqgxtv) ugeclixcbejznjnts = pwknwgdtsgxrklugaydksw + 1; else hi = pwknwgdtsgxrklugaydksw - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int mcvpbuuzdaxppvkohnvmp = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) mcvpbuuzdaxppvkohnvmp++;
    printf("%d\n", mcvpbuuzdaxppvkohnvmp);
    return 0;
}
