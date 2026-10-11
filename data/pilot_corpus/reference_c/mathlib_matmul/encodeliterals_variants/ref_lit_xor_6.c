#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xAE7B632 ^ 0xAE7B632); i < N; i++)
        for (int j = (0x1C9B5418 ^ 0x1C9B5418); j < N; j++) { a[i][j] = (i + (0x4A0F5F2D ^ 0x4A0F5F2C)) * (j + (0x64BF0664 ^ 0x64BF0666)) % (0x4F741F53 ^ 0x4F741F54); b[i][j] = (i * (0x4820983A ^ 0x48209839) + j) % (0x49716AE3 ^ 0x49716AE6); }
    for (int i = (0x10C2D1B1 ^ 0x10C2D1B1); i < N; i++)
        for (int j = (0x45062E86 ^ 0x45062E86); j < N; j++) {
            int s = (0x59360A2C ^ 0x59360A2C);
            for (int k = (0x4856B6D5 ^ 0x4856B6D5); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x66471CDC ^ 0x66471CDC);
    for (int i = (0x5508F826 ^ 0x5508F826); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x3FB351D ^ 0x3FB351D);
}
