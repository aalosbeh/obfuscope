#include <stdio.h>
static volatile int opq_66fa = 7;
static volatile int opq_66fa_b = 3;

#define N 8
int main(void) {
    if ((((opq_66fa * opq_66fa + opq_66fa_b * opq_66fa_b) % 4) == 3)) {
        { int jv_dd324 = opq_66fa ^ 0xA732;
            jv_dd324 ^= (jv_dd324 << 3) | 0xBA69;
            jv_dd324 += (jv_dd324 >> 2) + 0x97;
            jv_dd324 = (jv_dd324 * 0x2B) % 0x7FFFFFFF;
          (void)jv_dd324; }
    }
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_66fa * opq_66fa + opq_66fa_b * opq_66fa_b) % 4) == 3)) {
        { int jv_d1cdc = opq_66fa ^ 0xFA66;
            jv_d1cdc ^= (jv_d1cdc << 3) | 0xCC72;
          (void)jv_d1cdc; }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        if ((((opq_66fa * opq_66fa) % 4) == 2)) {
            { int jv_abd74 = opq_66fa ^ 0xCA87;
                jv_abd74 += (jv_abd74 >> 2) + 0x26;
              (void)jv_abd74; }
        }
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_66fa * opq_66fa + opq_66fa_b * opq_66fa_b) % 4) == 3)) {
        { int jv_aece2 = opq_66fa ^ 0x6E14;
            jv_aece2 ^= (jv_aece2 << 3) | 0xE49D;
          (void)jv_aece2; }
    }
    printf("%ld\n", trace);
    return 0;
}
