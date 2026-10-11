#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x6A5BC3ED ^ 0x6A5BC3ED); i < N; i++)
        for (int j = (0x14A798E1 ^ 0x14A798E1); j < N; j++) { a[i][j] = (i + (0x3E04C825 ^ 0x3E04C824)) * (j + (0x9503237 ^ 0x9503235)) % (0x58965299 ^ 0x5896529E); b[i][j] = (i * (0x28BA6DF ^ 0x28BA6DC) + j) % (0x2B9BD281 ^ 0x2B9BD284); }
    for (int i = (0x565AB42C ^ 0x565AB42C); i < N; i++)
        for (int j = (0x1B28516A ^ 0x1B28516A); j < N; j++) {
            int s = (0x286A2037 ^ 0x286A2037);
            for (int k = (0x411B436A ^ 0x411B436A); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x57222D6C ^ 0x57222D6C);
    for (int i = (0x19254F6A ^ 0x19254F6A); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x21DEAD27 ^ 0x21DEAD27);
}
