#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x40F864DB ^ 0x40F864DB); i < N; i++)
        for (int j = (0x4C9C76AC ^ 0x4C9C76AC); j < N; j++) { a[i][j] = (i + (0x6027D90E ^ 0x6027D90F)) * (j + (0x4ABB79DE ^ 0x4ABB79DC)) % (0x6377BF78 ^ 0x6377BF7F); b[i][j] = (i * (0x60AD0AE2 ^ 0x60AD0AE1) + j) % (0x4A6559E ^ 0x4A6559B); }
    for (int i = (0x7C57E345 ^ 0x7C57E345); i < N; i++)
        for (int j = (0x970AC72 ^ 0x970AC72); j < N; j++) {
            int s = (0x3E1A8975 ^ 0x3E1A8975);
            for (int k = (0x7783EE38 ^ 0x7783EE38); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x4CCBF7FF ^ 0x4CCBF7FF);
    for (int i = (0x20EA540C ^ 0x20EA540C); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x44C7B6C1 ^ 0x44C7B6C1);
}
