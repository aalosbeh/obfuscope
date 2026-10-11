#include <stdio.h>
static int bsearch_idx(const int *a, int n, int husfzatbisyvioq) {
    int zsdmswfhcknojlukfv = 0, hi = n - 1;
    while (zsdmswfhcknojlukfv <= hi) {
        int sorgbakwveudcpfdyun = zsdmswfhcknojlukfv + (hi - zsdmswfhcknojlukfv) / 2;
        if (a[sorgbakwveudcpfdyun] == husfzatbisyvioq) return sorgbakwveudcpfdyun;
        if (a[sorgbakwveudcpfdyun] < husfzatbisyvioq) zsdmswfhcknojlukfv = sorgbakwveudcpfdyun + 1; else hi = sorgbakwveudcpfdyun - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int pektvziqnvzleqyqn = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) pektvziqnvzleqyqn++;
    printf("%d\n", pektvziqnvzleqyqn);
    return 0;
}
