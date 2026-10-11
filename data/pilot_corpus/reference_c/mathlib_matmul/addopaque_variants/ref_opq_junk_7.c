#include <stdio.h>
static volatile int opq_ff62 = 7;
static volatile int opq_ff62_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_ff62 * opq_ff62 + opq_ff62_b * opq_ff62_b) % 4) == 3)) {
        { int jv_7638a = opq_ff62 ^ 0xA376;
            jv_7638a ^= (jv_7638a << 3) | 0xC180;
            jv_7638a = (jv_7638a * 0x1F) % 0x7FFFFFFF;
            jv_7638a += (jv_7638a >> 2) + 0xED;
          (void)jv_7638a; }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
        if ((((opq_ff62 * opq_ff62) % 4) == 2)) {
            { int jv_10e50 = opq_ff62 ^ 0xC34E;
                jv_10e50 += (jv_10e50 >> 2) + 0xD2;
                jv_10e50 ^= (jv_10e50 << 3) | 0x2CD3;
              (void)jv_10e50; }
        }
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_ff62 * opq_ff62 + opq_ff62_b * opq_ff62_b) % 4) == 3)) {
            { int jv_88a79 = opq_ff62 ^ 0xB404;
                jv_88a79 = (jv_88a79 * 0x26) % 0x7FFFFFFF;
              (void)jv_88a79; }
        }
            c[i][j] = s;
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if ((((opq_ff62 * opq_ff62) % 4) == 2)) {
        { int jv_2211f = opq_ff62 ^ 0x8CAA;
            jv_2211f ^= (jv_2211f << 3) | 0x3494;
            jv_2211f = (jv_2211f * 0x15) % 0x7FFFFFFF;
            jv_2211f += (jv_2211f >> 2) + 0x7F;
          (void)jv_2211f; }
    }
    return 0;
}
