#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_159109) {
    int v_caefa4 = 0, hi = n - 1;
    while (v_caefa4 <= hi) {
        int v_80adde = v_caefa4 + (hi - v_caefa4) / 2;
        if (a[v_80adde] == v_159109) return v_80adde;
        if (a[v_80adde] < v_159109) v_caefa4 = v_80adde + 1; else hi = v_80adde - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_319a7d = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_319a7d++;
    printf("%d\n", v_319a7d);
    return 0;
}
