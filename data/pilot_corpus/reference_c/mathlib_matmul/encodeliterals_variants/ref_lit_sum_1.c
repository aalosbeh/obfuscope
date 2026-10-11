#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x138 - 0x138); i < N; i++)
        for (int j = (0xF29 - 0xF29); j < N; j++) { a[i][j] = (i + (0x106 - 0x105)) * (j + (0x6E3 - 0x6E1)) % (0x1E0 - 0x1D9); b[i][j] = (i * (0x35E - 0x35B) + j) % (0x768 - 0x763); }
    for (int i = (0xAC1 - 0xAC1); i < N; i++)
        for (int j = (0xA67 - 0xA67); j < N; j++) {
            int s = (0xCB5 - 0xCB5);
            for (int k = (0xDA1 - 0xDA1); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x997 - 0x997);
    for (int i = (0x5F2 - 0x5F2); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0xDA2 - 0xDA2);
}
