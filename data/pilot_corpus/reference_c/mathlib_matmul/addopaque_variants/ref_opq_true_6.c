#include <stdio.h>
static volatile int opq_4727 = 7;
static volatile int opq_4727_b = 3;

#define N 8
int main(void) {
    if (((opq_4727 * opq_4727 - opq_4727) % 2 == 0)) { opq_4727_b ^= 0; }
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_4727 * (opq_4727 + 1)) % 2) == 0)) { opq_4727_b ^= 0; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_4727 * (opq_4727 + 1)) % 2) == 0)) { opq_4727_b ^= 0; }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_4727 * opq_4727 + opq_4727) % 2) == 0)) { opq_4727_b ^= 0; }
            c[i][j] = s;
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return 0;
}
