#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x7BEE14F2 ^ 0x7BEE14F2); i < N; i++)
        for (int j = (0x2B65F81A ^ 0x2B65F81A); j < N; j++) { a[i][j] = (i + (0xE82BEF9 ^ 0xE82BEF8)) * (j + (0x39192FD2 ^ 0x39192FD0)) % (0x3DC0B812 ^ 0x3DC0B815); b[i][j] = (i * (0xBE4CA49 ^ 0xBE4CA4A) + j) % (0x7B7E2819 ^ 0x7B7E281C); }
    for (int i = (0x5D1C2F8D ^ 0x5D1C2F8D); i < N; i++)
        for (int j = (0x3CD308B0 ^ 0x3CD308B0); j < N; j++) {
            int s = (0x5A9CC3DC ^ 0x5A9CC3DC);
            for (int k = (0x67199279 ^ 0x67199279); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x4BA25DEC ^ 0x4BA25DEC);
    for (int i = (0x545AC55E ^ 0x545AC55E); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x7B64D889 ^ 0x7B64D889);
}
