#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0xF19 - 0xF19); i < N; i++)
        for (int j = (0x674AE5EC ^ 0x674AE5EC); j < N; j++) { a[i][j] = (i + (0x565 - 0x564)) * (j + (0x62A - 0x628)) % (0xEB14CA3 ^ 0xEB14CA4); b[i][j] = (i * (0x1C8A1EE8 ^ 0x1C8A1EEB) + j) % (0x7E827B44 ^ 0x7E827B41); }
    for (int i = (0x78A806D9 ^ 0x78A806D9); i < N; i++)
        for (int j = (0x18C73E88 ^ 0x18C73E88); j < N; j++) {
            int s = (0x66827F2A ^ 0x66827F2A);
            for (int k = (0x3F38BD00 ^ 0x3F38BD00); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0x301A22DE ^ 0x301A22DE);
    for (int i = (0x1BD73EC1 ^ 0x1BD73EC1); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x35554A60 ^ 0x35554A60);
}
