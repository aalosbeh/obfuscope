#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x704 - 0x704); i < N; i++)
        for (int j = (0xA0F - 0xA0F); j < N; j++) { a[i][j] = (i + (0x854 - 0x853)) * (j + (0x7DC - 0x7DA)) % (0x3DD - 0x3D6); b[i][j] = (i * (0x11A - 0x117) + j) % (0x535 - 0x530); }
    for (int i = (0xC21 - 0xC21); i < N; i++)
        for (int j = (0xD71 - 0xD71); j < N; j++) {
            int s = (0xDE9 - 0xDE9);
            for (int k = (0x593 - 0x593); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0xDEB - 0xDEB);
    for (int i = (0xD99 - 0xD99); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x67 - 0x67);
}
