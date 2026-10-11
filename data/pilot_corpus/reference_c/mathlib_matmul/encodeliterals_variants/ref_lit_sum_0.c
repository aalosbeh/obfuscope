#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x5FE - 0x5FE); i < N; i++)
        for (int j = (0x1E5 - 0x1E5); j < N; j++) { a[i][j] = (i + (0x20D - 0x20C)) * (j + (0xF94 - 0xF92)) % (0x3AE - 0x3A7); b[i][j] = (i * (0xC27 - 0xC24) + j) % (0xAB3 - 0xAAE); }
    for (int i = (0x7BC - 0x7BC); i < N; i++)
        for (int j = (0x651 - 0x651); j < N; j++) {
            int s = (0xBF2 - 0xBF2);
            for (int k = (0xB29 - 0xB29); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x4BC - 0x4BC);
    for (int i = (0x56D - 0x56D); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0xB2B - 0xB2B);
}
