#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x5C0395CD ^ 0x5C0395CD); i < N; i++)
        for (int j = (0x31D054AF ^ 0x31D054AF); j < N; j++) { a[i][j] = (i + (0x266C5424 ^ 0x266C5425)) * (j + (0x3638FDC6 ^ 0x3638FDC4)) % (0x2FE1EF25 ^ 0x2FE1EF22); b[i][j] = (i * (0x1F11802A ^ 0x1F118029) + j) % (0x1D9B08B5 ^ 0x1D9B08B0); }
    for (int i = (0x3E6DBB53 ^ 0x3E6DBB53); i < N; i++)
        for (int j = (0x7E102977 ^ 0x7E102977); j < N; j++) {
            int s = (0x4443AF5A ^ 0x4443AF5A);
            for (int k = (0x1560AFF6 ^ 0x1560AFF6); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x58E2E32 ^ 0x58E2E32);
    for (int i = (0x1571F0A3 ^ 0x1571F0A3); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x5357FC6B ^ 0x5357FC6B);
}
