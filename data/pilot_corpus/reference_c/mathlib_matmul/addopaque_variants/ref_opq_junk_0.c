#include <stdio.h>
static volatile int opq_8cfe = 7;
static volatile int opq_8cfe_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_8cfe * opq_8cfe + opq_8cfe_b * opq_8cfe_b) % 4) == 3)) {
            { int jv_2515e = opq_8cfe ^ 0xA3D2;
                jv_2515e = (jv_2515e * 0xC) % 0x7FFFFFFF;
              (void)jv_2515e; }
        }
            int s = 0;
        if ((((opq_8cfe * opq_8cfe + opq_8cfe_b * opq_8cfe_b) % 4) == 3)) {
            { int jv_39cc6 = opq_8cfe ^ 0x23FB;
                jv_39cc6 = (jv_39cc6 * 0x24) % 0x7FFFFFFF;
              (void)jv_39cc6; }
        }
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = 0;
    if ((((opq_8cfe * opq_8cfe) % 4) == 2)) {
        { int jv_13dbd = opq_8cfe ^ 0x7586;
            jv_13dbd += (jv_13dbd >> 2) + 0x59;
            jv_13dbd ^= (jv_13dbd << 3) | 0x687F;
          (void)jv_13dbd; }
    }
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if ((((opq_8cfe * opq_8cfe + opq_8cfe_b * opq_8cfe_b) % 4) == 3)) {
        { int jv_c97ba = opq_8cfe ^ 0x3523;
            jv_c97ba += (jv_c97ba >> 2) + 0x9E;
            jv_c97ba ^= (jv_c97ba << 3) | 0xCC2E;
            jv_c97ba = (jv_c97ba * 0x1E) % 0x7FFFFFFF;
          (void)jv_c97ba; }
    }
    return 0;
}
