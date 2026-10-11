#include <stdio.h>
static int bsearch_idx(const int *a, int n, int v_adba54) {
    int v_4981de = 0, hi = n - 1;
    while (v_4981de <= hi) {
        int v_84e906 = v_4981de + (hi - v_4981de) / 2;
        if (a[v_84e906] == v_adba54) return v_84e906;
        if (a[v_84e906] < v_adba54) v_4981de = v_84e906 + 1; else hi = v_84e906 - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int v_4f2193 = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) v_4f2193++;
    printf("%d\n", v_4f2193);
    return 0;
}
