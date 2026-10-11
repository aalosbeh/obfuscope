#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x7B6D3CDD ^ 0x7B6D3CDD); i < N; i++)
        for (int j = (0x37A435F3 ^ 0x37A435F3); j < N; j++) { a[i][j] = (i + (0x6D551DC1 ^ 0x6D551DC0)) * (j + (0xD4D - 0xD4B)) % (0x3998B7C1 ^ 0x3998B7C6); b[i][j] = (i * (0x867 - 0x864) + j) % (0x20CC7263 ^ 0x20CC7266); }
    for (int i = (0x7D0 - 0x7D0); i < N; i++)
        for (int j = (0x9D15E48 ^ 0x9D15E48); j < N; j++) {
            int s = (0xFE6 - 0xFE6);
            for (int k = (0xE7A - 0xE7A); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0xCC3 - 0xCC3);
    for (int i = (0x780E1C3A ^ 0x780E1C3A); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x3E9 - 0x3E9);
}
