#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_4efdab) {
    int v_63abd4 = 0, hi = n - 1;
    while (v_63abd4 <= hi) {
        int v_32edb1 = v_63abd4 + (hi - v_63abd4) / 2;
        if (a[v_32edb1] == v_4efdab) return v_32edb1;
        if (a[v_32edb1] < v_4efdab) v_63abd4 = v_32edb1 + 1; else hi = v_32edb1 - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_5b3b1b = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_5b3b1b++;
    printf("%d\n", v_5b3b1b);
    return 0;
}
