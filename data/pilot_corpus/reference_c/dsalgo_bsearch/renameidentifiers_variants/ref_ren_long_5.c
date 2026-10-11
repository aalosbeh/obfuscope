#include <stdio.h>
static int bsearch_idx(const int *a, int n, int qcuyewrsugnggjuhfjwm) {
    int cqrdqxtcxizivii = 0, hi = n - 1;
    while (cqrdqxtcxizivii <= hi) {
        int lpnzxuumlzbxnllkec = cqrdqxtcxizivii + (hi - cqrdqxtcxizivii) / 2;
        if (a[lpnzxuumlzbxnllkec] == qcuyewrsugnggjuhfjwm) return lpnzxuumlzbxnllkec;
        if (a[lpnzxuumlzbxnllkec] < qcuyewrsugnggjuhfjwm) cqrdqxtcxizivii = lpnzxuumlzbxnllkec + 1; else hi = lpnzxuumlzbxnllkec - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int ofkhibiycbjpbuokbbfqph = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) ofkhibiycbjpbuokbbfqph++;
    printf("%d\n", ofkhibiycbjpbuokbbfqph);
    return 0;
}
