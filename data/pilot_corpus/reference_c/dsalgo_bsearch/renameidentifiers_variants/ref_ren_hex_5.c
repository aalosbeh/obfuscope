#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_98ed3d) {
    int v_36df20 = 0, hi = n - 1;
    while (v_36df20 <= hi) {
        int v_1fb079 = v_36df20 + (hi - v_36df20) / 2;
        if (a[v_1fb079] == v_98ed3d) return v_1fb079;
        if (a[v_1fb079] < v_98ed3d) v_36df20 = v_1fb079 + 1; else hi = v_1fb079 - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_d37d0e = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_d37d0e++;
    printf("%d\n", v_d37d0e);
    return 0;
}
