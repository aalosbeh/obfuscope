#include <stdio.h>
static int bsearch_idx(const int *a, int n, int jgzwzlgnjrwuoevpwa) {
    int bzcsfdserxsnuiwhs = 0, hi = n - 1;
    while (bzcsfdserxsnuiwhs <= hi) {
        int jovhdihsowsswnmi = bzcsfdserxsnuiwhs + (hi - bzcsfdserxsnuiwhs) / 2;
        if (a[jovhdihsowsswnmi] == jgzwzlgnjrwuoevpwa) return jovhdihsowsswnmi;
        if (a[jovhdihsowsswnmi] < jgzwzlgnjrwuoevpwa) bzcsfdserxsnuiwhs = jovhdihsowsswnmi + 1; else hi = jovhdihsowsswnmi - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int ptzacyyofvjsebbype = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) ptzacyyofvjsebbype++;
    printf("%d\n", ptzacyyofvjsebbype);
    return 0;
}
