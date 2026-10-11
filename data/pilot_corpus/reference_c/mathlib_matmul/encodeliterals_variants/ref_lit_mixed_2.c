#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x5FD - 0x5FD); i < N; i++)
        for (int j = (0x4D3 - 0x4D3); j < N; j++) { a[i][j] = (i + (0x99B - 0x99A)) * (j + (0x464 - 0x462)) % (0xB6D - 0xB66); b[i][j] = (i * (0xD15 - 0xD12) + j) % (0xBBF - 0xBBA); }
    for (int i = (0xFDF - 0xFDF); i < N; i++)
        for (int j = (0x3BACA273 ^ 0x3BACA273); j < N; j++) {
            int s = (0x1F6828D4 ^ 0x1F6828D4);
            for (int k = (0x4A0 - 0x4A0); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x749 - 0x749);
    for (int i = (0x908099 ^ 0x908099); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x5DB - 0x5DB);
}
