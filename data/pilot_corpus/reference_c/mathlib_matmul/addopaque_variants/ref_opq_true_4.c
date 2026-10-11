#include <stdio.h>
static volatile int opq_f9e8 = 7;
static volatile int opq_f9e8_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_f9e8 * (opq_f9e8 + 1)) % 2) == 0)) { opq_f9e8_b ^= 0; }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_f9e8 * (opq_f9e8 + 1)) % 2) == 0)) { opq_f9e8_b ^= 0; }
            c[i][j] = s;
        }
    long trace = 0;
    if (((opq_f9e8 * opq_f9e8 - opq_f9e8) % 2 == 0)) { opq_f9e8_b ^= 0; }
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if (((opq_f9e8 * opq_f9e8 - opq_f9e8) % 2 == 0)) { opq_f9e8_b ^= 0; }
    return 0;
}
