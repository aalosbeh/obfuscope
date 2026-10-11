#include <stdio.h>
static int bsearch_idx(const int *a, int n, int irwgwyjlzbhirchkpgnfjv) {
    int tzyufntfwwbbgwfvopip = 0, hi = n - 1;
    while (tzyufntfwwbbgwfvopip <= hi) {
        int okdirtngjdgruo = tzyufntfwwbbgwfvopip + (hi - tzyufntfwwbbgwfvopip) / 2;
        if (a[okdirtngjdgruo] == irwgwyjlzbhirchkpgnfjv) return okdirtngjdgruo;
        if (a[okdirtngjdgruo] < irwgwyjlzbhirchkpgnfjv) tzyufntfwwbbgwfvopip = okdirtngjdgruo + 1; else hi = okdirtngjdgruo - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int vetneiprfmnvzmgnhylqm = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) vetneiprfmnvzmgnhylqm++;
    printf("%d\n", vetneiprfmnvzmgnhylqm);
    return 0;
}
