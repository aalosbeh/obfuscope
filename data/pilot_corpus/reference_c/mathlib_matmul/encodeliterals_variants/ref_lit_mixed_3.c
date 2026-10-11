#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xF00 - 0xF00); i < N; i++)
        for (int j = (0x34C6492E ^ 0x34C6492E); j < N; j++) { a[i][j] = (i + (0xE4C - 0xE4B)) * (j + (0x846 - 0x844)) % (0x650 - 0x649); b[i][j] = (i * (0x59AA3CF8 ^ 0x59AA3CFB) + j) % (0x4A75B79E ^ 0x4A75B79B); }
    for (int i = (0x3B2 - 0x3B2); i < N; i++)
        for (int j = (0x7B1BB6F4 ^ 0x7B1BB6F4); j < N; j++) {
            int s = (0x3259DF20 ^ 0x3259DF20);
            for (int k = (0x40C - 0x40C); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x29A - 0x29A);
    for (int i = (0xA5B - 0xA5B); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0xBB1 - 0xBB1);
}
