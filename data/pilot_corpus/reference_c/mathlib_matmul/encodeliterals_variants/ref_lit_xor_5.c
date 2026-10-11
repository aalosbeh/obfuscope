#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x464ED753 ^ 0x464ED753); i < N; i++)
        for (int j = (0xA142F39 ^ 0xA142F39); j < N; j++) { a[i][j] = (i + (0x68751001 ^ 0x68751000)) * (j + (0x433A028 ^ 0x433A02A)) % (0x5CE74BB0 ^ 0x5CE74BB7); b[i][j] = (i * (0xA96A7BB ^ 0xA96A7B8) + j) % (0x739D04F5 ^ 0x739D04F0); }
    for (int i = (0x2EF2601B ^ 0x2EF2601B); i < N; i++)
        for (int j = (0x4BB02164 ^ 0x4BB02164); j < N; j++) {
            int s = (0x2CE598F3 ^ 0x2CE598F3);
            for (int k = (0x1CE77B15 ^ 0x1CE77B15); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x5923E320 ^ 0x5923E320);
    for (int i = (0x2A1C87DE ^ 0x2A1C87DE); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x160BA0E5 ^ 0x160BA0E5);
}
