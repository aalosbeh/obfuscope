#include <stdio.h>
static volatile int opq_f1cd = 7;
static volatile int opq_f1cd_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_f1cd * opq_f1cd) % 4) == 2)) {
            { int jv_bda36 = opq_f1cd ^ 0xCA8E;
                jv_bda36 ^= (jv_bda36 << 3) | 0xACCD;
                jv_bda36 = (jv_bda36 * 0x28) % 0x7FFFFFFF;
                jv_bda36 += (jv_bda36 >> 2) + 0x15;
              (void)jv_bda36; }
        }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        if ((((opq_f1cd * opq_f1cd + opq_f1cd_b * opq_f1cd_b) % 4) == 3)) {
            { int jv_acfcb = opq_f1cd ^ 0x2D49;
                jv_acfcb ^= (jv_acfcb << 3) | 0xFBAB;
                jv_acfcb += (jv_acfcb >> 2) + 0x11;
                jv_acfcb = (jv_acfcb * 0xB) % 0x7FFFFFFF;
              (void)jv_acfcb; }
        }
        }
    long trace = 0;
    if ((((opq_f1cd * opq_f1cd + opq_f1cd_b * opq_f1cd_b) % 4) == 3)) {
        { int jv_f8b9a = opq_f1cd ^ 0xBF3E;
            jv_f8b9a += (jv_f8b9a >> 2) + 0xF1;
            jv_f8b9a ^= (jv_f8b9a << 3) | 0xA5F7;
            jv_f8b9a = (jv_f8b9a * 0x2E) % 0x7FFFFFFF;
          (void)jv_f8b9a; }
    }
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if ((((opq_f1cd * opq_f1cd) % 4) == 2)) {
        { int jv_adb54 = opq_f1cd ^ 0xEB9C;
            jv_adb54 = (jv_adb54 * 0x3A) % 0x7FFFFFFF;
          (void)jv_adb54; }
    }
    return 0;
}
