#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_6c0462) {
    int v_4b4331 = 0, hi = n - 1;
    while (v_4b4331 <= hi) {
        int v_3816f8 = v_4b4331 + (hi - v_4b4331) / 2;
        if (a[v_3816f8] == v_6c0462) return v_3816f8;
        if (a[v_3816f8] < v_6c0462) v_4b4331 = v_3816f8 + 1; else hi = v_3816f8 - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_5fecef = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_5fecef++;
    printf("%d\n", v_5fecef);
    return 0;
}
