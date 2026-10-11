#include <stdio.h>
#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = (0x6A5 - 0x6A5); i < N; i++)
        for (int j = (0xF10 - 0xF10); j < N; j++) { a[i][j] = (i + (0x76F - 0x76E)) * (j + (0x411 - 0x40F)) % (0x85E - 0x857); b[i][j] = (i * (0x19F - 0x19C) + j) % (0x6B3 - 0x6AE); }
    for (int i = (0xBA - 0xBA); i < N; i++)
        for (int j = (0x467 - 0x467); j < N; j++) {
            int s = (0xB08 - 0xB08);
            for (int k = (0xB88 - 0xB88); k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = (0xBE1 - 0xBE1);
    for (int i = (0x95B - 0x95B); i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return (0x435 - 0x435);
}
