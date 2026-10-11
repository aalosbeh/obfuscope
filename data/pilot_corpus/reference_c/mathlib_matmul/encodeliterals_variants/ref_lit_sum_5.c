#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xEAB - 0xEAB); i < N; i++)
        for (int j = (0xF0E - 0xF0E); j < N; j++) { a[i][j] = (i + (0x5C7 - 0x5C6)) * (j + (0x6C2 - 0x6C0)) % (0xEBC - 0xEB5); b[i][j] = (i * (0xE94 - 0xE91) + j) % (0x398 - 0x393); }
    for (int i = (0x1B3 - 0x1B3); i < N; i++)
        for (int j = (0x255 - 0x255); j < N; j++) {
            int s = (0xEA5 - 0xEA5);
            for (int k = (0x67D - 0x67D); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x8A1 - 0x8A1);
    for (int i = (0x76F - 0x76F); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x9C5 - 0x9C5);
}
