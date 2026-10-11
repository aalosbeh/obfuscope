#include <stdio.h>
static volatile int opq_d57a = 7;
static volatile int opq_d57a_b = 3;

#define N 8
int main(void) {
    if ((((opq_d57a * opq_d57a + opq_d57a_b * opq_d57a_b) % 4) == 3)) {
        { int jv_a890e = opq_d57a ^ 0x61;
            jv_a890e += (jv_a890e >> 2) + 0xA5;
          (void)jv_a890e; }
    }
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_d57a * opq_d57a + opq_d57a_b * opq_d57a_b) % 4) == 3)) {
            { int jv_60227 = opq_d57a ^ 0xD169;
                jv_60227 = (jv_60227 * 0x34) % 0x7FFFFFFF;
                jv_60227 ^= (jv_60227 << 3) | 0x83EC;
                jv_60227 += (jv_60227 >> 2) + 0x9F;
              (void)jv_60227; }
        }
            c[i][j] = s;
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_d57a * opq_d57a + opq_d57a_b * opq_d57a_b) % 4) == 3)) {
        { int jv_3f884 = opq_d57a ^ 0x5A6D;
            jv_3f884 += (jv_3f884 >> 2) + 0xCB;
            jv_3f884 = (jv_3f884 * 0x3A) % 0x7FFFFFFF;
          (void)jv_3f884; }
    }
    printf("%ld\n", trace);
    if ((((opq_d57a * opq_d57a) % 4) == 2)) {
        { int jv_47fbc = opq_d57a ^ 0x8923;
            jv_47fbc ^= (jv_47fbc << 3) | 0x13A9;
            jv_47fbc = (jv_47fbc * 0x26) % 0x7FFFFFFF;
          (void)jv_47fbc; }
    }
    return 0;
}
