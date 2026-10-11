#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x6E0D0FA3 ^ 0x6E0D0FA3); i < N; i++)
        for (int j = (0x595EFB28 ^ 0x595EFB28); j < N; j++) { a[i][j] = (i + (0x6CE3D03C ^ 0x6CE3D03D)) * (j + (0x55F2DFFE ^ 0x55F2DFFC)) % (0xECB08E5 ^ 0xECB08E2); b[i][j] = (i * (0x6879CB9D ^ 0x6879CB9E) + j) % (0xC27E30C ^ 0xC27E309); }
    for (int i = (0x4BC581AD ^ 0x4BC581AD); i < N; i++)
        for (int j = (0x127F9DDC ^ 0x127F9DDC); j < N; j++) {
            int s = (0x183E43EB ^ 0x183E43EB);
            for (int k = (0x674896F3 ^ 0x674896F3); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x8A62E5B ^ 0x8A62E5B);
    for (int i = (0x5E009018 ^ 0x5E009018); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x791F7E25 ^ 0x791F7E25);
}
