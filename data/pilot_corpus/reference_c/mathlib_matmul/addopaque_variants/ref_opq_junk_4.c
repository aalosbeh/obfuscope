#include <stdio.h>
static volatile int opq_5f1f = 7;
static volatile int opq_5f1f_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_5f1f * opq_5f1f) % 4) == 2)) {
            { int jv_3bcfa = opq_5f1f ^ 0x83F6;
                jv_3bcfa = (jv_3bcfa * 0x20) % 0x7FFFFFFF;
                jv_3bcfa += (jv_3bcfa >> 2) + 0xCE;
                jv_3bcfa ^= (jv_3bcfa << 3) | 0x73B2;
              (void)jv_3bcfa; }
        }
            c[i][j] = s;
        if ((((opq_5f1f * opq_5f1f + opq_5f1f_b * opq_5f1f_b) % 4) == 3)) {
            { int jv_5724f = opq_5f1f ^ 0x106C;
                jv_5724f ^= (jv_5724f << 3) | 0xEEC8;
                jv_5724f += (jv_5724f >> 2) + 0x15;
                jv_5724f = (jv_5724f * 0x7) % 0x7FFFFFFF;
              (void)jv_5724f; }
        }
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_5f1f * opq_5f1f) % 4) == 2)) {
        { int jv_4c5bf = opq_5f1f ^ 0xC3D0;
            jv_4c5bf ^= (jv_4c5bf << 3) | 0x9523;
            jv_4c5bf += (jv_4c5bf >> 2) + 0x1C;
            jv_4c5bf = (jv_4c5bf * 0x23) % 0x7FFFFFFF;
          (void)jv_4c5bf; }
    }
    printf("%ld\n", trace);
    if ((((opq_5f1f * opq_5f1f) % 4) == 2)) {
        { int jv_4791b = opq_5f1f ^ 0xA0BD;
            jv_4791b ^= (jv_4791b << 3) | 0x44AA;
            jv_4791b = (jv_4791b * 0x30) % 0x7FFFFFFF;
            jv_4791b += (jv_4791b >> 2) + 0x66;
          (void)jv_4791b; }
    }
    return 0;
}
