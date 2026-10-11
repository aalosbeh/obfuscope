#include <stdio.h>
static volatile int opq_5c16 = 7;
static volatile int opq_5c16_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
        if ((((opq_5c16 * opq_5c16 + opq_5c16_b * opq_5c16_b) % 4) == 3)) {
            { int jv_3b175 = opq_5c16 ^ 0xFF35;
                jv_3b175 += (jv_3b175 >> 2) + 0x48;
              (void)jv_3b175; }
        }
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_5c16 * opq_5c16 + opq_5c16_b * opq_5c16_b) % 4) == 3)) {
            { int jv_df2ef = opq_5c16 ^ 0x3BE3;
                jv_df2ef ^= (jv_df2ef << 3) | 0x6DC5;
                jv_df2ef = (jv_df2ef * 0x2E) % 0x7FFFFFFF;
              (void)jv_df2ef; }
        }
            c[i][j] = s;
        if (((opq_5c16 * opq_5c16 - opq_5c16) % 2 == 0)) { opq_5c16_b ^= 0; }
        }
    long trace = 0;
    if ((((opq_5c16 * opq_5c16 + opq_5c16_b * opq_5c16_b) % 4) == 3)) {
        { int jv_83c6c = opq_5c16 ^ 0xB40A;
            jv_83c6c = (jv_83c6c * 0x28) % 0x7FFFFFFF;
          (void)jv_83c6c; }
    }
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return 0;
}
