#include <stdio.h>
static volatile int opq_f771 = 7;
static volatile int opq_f771_b = 3;

#define N 8
int main(void) {
    if (((opq_f771 * opq_f771 - opq_f771) % 2 == 0)) { opq_f771_b ^= 0; }
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_f771 * (opq_f771 + 1)) % 2) == 0)) { opq_f771_b ^= 0; }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = 0;
    if ((((opq_f771 * opq_f771 + opq_f771) % 2) == 0)) { opq_f771_b ^= 0; }
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_f771 * (opq_f771 + 1)) % 2) == 0)) { opq_f771_b ^= 0; }
    printf("%ld\n", trace);
    return 0;
}
