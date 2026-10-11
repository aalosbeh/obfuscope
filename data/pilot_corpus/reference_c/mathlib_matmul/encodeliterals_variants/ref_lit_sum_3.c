#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xC45 - 0xC45); i < N; i++)
        for (int j = (0x353 - 0x353); j < N; j++) { a[i][j] = (i + (0x3CF - 0x3CE)) * (j + (0xA83 - 0xA81)) % (0x695 - 0x68E); b[i][j] = (i * (0x12 - 0xF) + j) % (0x58D - 0x588); }
    for (int i = (0xF66 - 0xF66); i < N; i++)
        for (int j = (0x113 - 0x113); j < N; j++) {
            int s = (0x58 - 0x58);
            for (int k = (0x882 - 0x882); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x73 - 0x73);
    for (int i = (0x751 - 0x751); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x5AA - 0x5AA);
}
