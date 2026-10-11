#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_83bada) {
    int v_a24523 = 0, hi = n - 1;
    while (v_a24523 <= hi) {
        int v_ffe95b = v_a24523 + (hi - v_a24523) / 2;
        if (a[v_ffe95b] == v_83bada) return v_ffe95b;
        if (a[v_ffe95b] < v_83bada) v_a24523 = v_ffe95b + 1; else hi = v_ffe95b - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_266af3 = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_266af3++;
    printf("%d\n", v_266af3);
    return 0;
}
