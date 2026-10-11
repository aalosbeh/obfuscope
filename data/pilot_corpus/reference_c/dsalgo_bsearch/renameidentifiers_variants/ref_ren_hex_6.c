#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_16551f) {
    int v_943184 = 0, hi = n - 1;
    while (v_943184 <= hi) {
        int v_41647f = v_943184 + (hi - v_943184) / 2;
        if (a[v_41647f] == v_16551f) return v_41647f;
        if (a[v_41647f] < v_16551f) v_943184 = v_41647f + 1; else hi = v_41647f - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_98844e = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_98844e++;
    printf("%d\n", v_98844e);
    return 0;
}
