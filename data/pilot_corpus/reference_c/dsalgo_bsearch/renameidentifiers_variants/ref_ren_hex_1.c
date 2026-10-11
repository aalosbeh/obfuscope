#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_1dcc20) {
    int v_8dd922 = 0, hi = n - 1;
    while (v_8dd922 <= hi) {
        int v_3f11f2 = v_8dd922 + (hi - v_8dd922) / 2;
        if (a[v_3f11f2] == v_1dcc20) return v_3f11f2;
        if (a[v_3f11f2] < v_1dcc20) v_8dd922 = v_3f11f2 + 1; else hi = v_3f11f2 - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_317744 = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_317744++;
    printf("%d\n", v_317744);
    return 0;
}
