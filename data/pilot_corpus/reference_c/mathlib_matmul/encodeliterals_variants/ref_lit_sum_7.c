#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x6D5 - 0x6D5); i < N; i++)
        for (int j = (0xC5B - 0xC5B); j < N; j++) { a[i][j] = (i + (0x51D - 0x51C)) * (j + (0x599 - 0x597)) % (0x11F - 0x118); b[i][j] = (i * (0xF40 - 0xF3D) + j) % (0xB19 - 0xB14); }
    for (int i = (0x514 - 0x514); i < N; i++)
        for (int j = (0x806 - 0x806); j < N; j++) {
            int s = (0x8A9 - 0x8A9);
            for (int k = (0x60A - 0x60A); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x42C - 0x42C);
    for (int i = (0x315 - 0x315); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x57B - 0x57B);
}
