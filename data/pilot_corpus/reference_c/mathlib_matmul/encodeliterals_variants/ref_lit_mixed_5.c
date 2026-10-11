#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xAA9 - 0xAA9); i < N; i++)
        for (int j = (0xEE3 - 0xEE3); j < N; j++) { a[i][j] = (i + (0x927 - 0x926)) * (j + (0xF70 - 0xF6E)) % (0xEA1 - 0xE9A); b[i][j] = (i * (0x60A0CAA1 ^ 0x60A0CAA2) + j) % (0xCE7 - 0xCE2); }
    for (int i = (0x1123DEEC ^ 0x1123DEEC); i < N; i++)
        for (int j = (0x27B9917C ^ 0x27B9917C); j < N; j++) {
            int s = (0xB5D - 0xB5D);
            for (int k = (0x4C59AC27 ^ 0x4C59AC27); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x413 - 0x413);
    for (int i = (0xE83 - 0xE83); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x3A - 0x3A);
}
