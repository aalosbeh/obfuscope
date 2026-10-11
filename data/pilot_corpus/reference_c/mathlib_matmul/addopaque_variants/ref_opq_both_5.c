#include <stdio.h>
static volatile int opq_64b0 = 7;
static volatile int opq_64b0_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_64b0 * opq_64b0 + opq_64b0) % 2) == 0)) { opq_64b0_b ^= 0; }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if (((opq_64b0 * opq_64b0 - opq_64b0) % 2 == 0)) { opq_64b0_b ^= 0; }
            c[i][j] = s;
        if ((((opq_64b0 * opq_64b0 + opq_64b0) % 2) == 0)) { opq_64b0_b ^= 0; }
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_64b0 * opq_64b0) % 4) == 2)) {
        { int jv_8c3ec = opq_64b0 ^ 0xB61F;
            jv_8c3ec = (jv_8c3ec * 0x3D) % 0x7FFFFFFF;
            jv_8c3ec += (jv_8c3ec >> 2) + 0x67;
            jv_8c3ec ^= (jv_8c3ec << 3) | 0x6502;
          (void)jv_8c3ec; }
    }
    printf("%ld\n", trace);
    return 0;
}
