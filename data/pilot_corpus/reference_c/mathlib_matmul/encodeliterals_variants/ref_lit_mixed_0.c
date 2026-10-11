#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xD33 - 0xD33); i < N; i++)
        for (int j = (0x6ECED5F1 ^ 0x6ECED5F1); j < N; j++) { a[i][j] = (i + (0x2A6C703B ^ 0x2A6C703A)) * (j + (0xC67 - 0xC65)) % (0x495DEAC2 ^ 0x495DEAC5); b[i][j] = (i * (0x2D77CF50 ^ 0x2D77CF53) + j) % (0x547F88F4 ^ 0x547F88F1); }
    for (int i = (0x56080509 ^ 0x56080509); i < N; i++)
        for (int j = (0xE2 - 0xE2); j < N; j++) {
            int s = (0x58193470 ^ 0x58193470);
            for (int k = (0x93C - 0x93C); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x2B704B40 ^ 0x2B704B40);
    for (int i = (0x8F0 - 0x8F0); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x19480E07 ^ 0x19480E07);
}
