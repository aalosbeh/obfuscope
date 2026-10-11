#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x7EC714BA ^ 0x7EC714BA); i < N; i++)
        for (int j = (0x1166A8DF ^ 0x1166A8DF); j < N; j++) { a[i][j] = (i + (0xADD - 0xADC)) * (j + (0x402 - 0x400)) % (0x2AE - 0x2A7); b[i][j] = (i * (0x5FF5C66F ^ 0x5FF5C66C) + j) % (0x2AD - 0x2A8); }
    for (int i = (0x766D994A ^ 0x766D994A); i < N; i++)
        for (int j = (0xB84 - 0xB84); j < N; j++) {
            int s = (0xB2 - 0xB2);
            for (int k = (0x105 - 0x105); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x292BCBEB ^ 0x292BCBEB);
    for (int i = (0x3D05207E ^ 0x3D05207E); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0xD8 - 0xD8);
}
