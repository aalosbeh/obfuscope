#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x3D1 - 0x3D1); i < N; i++)
        for (int j = (0x1BF9D6F8 ^ 0x1BF9D6F8); j < N; j++) { a[i][j] = (i + (0x538CCD2D ^ 0x538CCD2C)) * (j + (0x211B799F ^ 0x211B799D)) % (0xB6C - 0xB65); b[i][j] = (i * (0x16BAA64F ^ 0x16BAA64C) + j) % (0xEC3 - 0xEBE); }
    for (int i = (0x2B233ECE ^ 0x2B233ECE); i < N; i++)
        for (int j = (0x78E9B433 ^ 0x78E9B433); j < N; j++) {
            int s = (0x5879402B ^ 0x5879402B);
            for (int k = (0x111B6692 ^ 0x111B6692); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x2BD2E7DE ^ 0x2BD2E7DE);
    for (int i = (0x86B - 0x86B); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x1A0539C9 ^ 0x1A0539C9);
}
