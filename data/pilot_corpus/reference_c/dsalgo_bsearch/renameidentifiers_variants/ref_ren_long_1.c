#include <stdio.h>
static int bsearch_idx(const int *a, int n, int oibfowrbbmzffsduaui) {
    int wznoanlptgxztb = 0, hi = n - 1;
    while (wznoanlptgxztb <= hi) {
        int ajbkkzfujwrvezrbus = wznoanlptgxztb + (hi - wznoanlptgxztb) / 2;
        if (a[ajbkkzfujwrvezrbus] == oibfowrbbmzffsduaui) return ajbkkzfujwrvezrbus;
        if (a[ajbkkzfujwrvezrbus] < oibfowrbbmzffsduaui) wznoanlptgxztb = ajbkkzfujwrvezrbus + 1; else hi = ajbkkzfujwrvezrbus - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int arzupbgzlltuckwbb = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) arzupbgzlltuckwbb++;
    printf("%d\n", arzupbgzlltuckwbb);
    return 0;
}
