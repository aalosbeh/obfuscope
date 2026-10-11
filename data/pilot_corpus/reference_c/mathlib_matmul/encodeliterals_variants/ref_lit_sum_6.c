#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x355 - 0x355); i < N; i++)
        for (int j = (0x505 - 0x505); j < N; j++) { a[i][j] = (i + (0x42 - 0x41)) * (j + (0x90E - 0x90C)) % (0xB6A - 0xB63); b[i][j] = (i * (0x10A - 0x107) + j) % (0xA4C - 0xA47); }
    for (int i = (0x600 - 0x600); i < N; i++)
        for (int j = (0x678 - 0x678); j < N; j++) {
            int s = (0x635 - 0x635);
            for (int k = (0xDCB - 0xDCB); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x331 - 0x331);
    for (int i = (0xEBA - 0xEBA); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0xEC3 - 0xEC3);
}
