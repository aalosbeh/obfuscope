#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x12772C15 ^ 0x12772C15); i < N; i++)
        for (int j = (0x4D2D04C4 ^ 0x4D2D04C4); j < N; j++) { a[i][j] = (i + (0x7844E351 ^ 0x7844E350)) * (j + (0x6F4FCDDF ^ 0x6F4FCDDD)) % (0x76902E78 ^ 0x76902E7F); b[i][j] = (i * (0x321BA43B ^ 0x321BA438) + j) % (0x122587E6 ^ 0x122587E3); }
    for (int i = (0x4BF385FD ^ 0x4BF385FD); i < N; i++)
        for (int j = (0x28DF38BA ^ 0x28DF38BA); j < N; j++) {
            int s = (0xA931CB9 ^ 0xA931CB9);
            for (int k = (0x5ED3355F ^ 0x5ED3355F); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x488371C6 ^ 0x488371C6);
    for (int i = (0x2E772FC6 ^ 0x2E772FC6); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x302DAA40 ^ 0x302DAA40);
}
