#include <stdio.h>
static volatile int opq_19b5 = 7;
static volatile int opq_19b5_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_19b5 * opq_19b5) % 4) == 2)) {
        { int jv_36560 = opq_19b5 ^ 0xF1E7;
            jv_36560 = (jv_36560 * 0x10) % 0x7FFFFFFF;
            jv_36560 ^= (jv_36560 << 3) | 0x4821;
            jv_36560 += (jv_36560 >> 2) + 0x71;
          (void)jv_36560; }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
        if ((((opq_19b5 * opq_19b5) % 4) == 2)) {
            { int jv_f56f0 = opq_19b5 ^ 0x8B1F;
                jv_f56f0 += (jv_f56f0 >> 2) + 0x8D;
                jv_f56f0 ^= (jv_f56f0 << 3) | 0x68E0;
              (void)jv_f56f0; }
        }
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        if ((((opq_19b5 * opq_19b5) % 4) == 2)) {
            { int jv_cecdb = opq_19b5 ^ 0x6D23;
                jv_cecdb = (jv_cecdb * 0x26) % 0x7FFFFFFF;
                jv_cecdb ^= (jv_cecdb << 3) | 0x3CD6;
              (void)jv_cecdb; }
        }
        }
    long trace = 0;
    if ((((opq_19b5 * opq_19b5) % 4) == 2)) {
        { int jv_bb1b1 = opq_19b5 ^ 0x5AB9;
            jv_bb1b1 ^= (jv_bb1b1 << 3) | 0x9A1D;
          (void)jv_bb1b1; }
    }
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return 0;
}
