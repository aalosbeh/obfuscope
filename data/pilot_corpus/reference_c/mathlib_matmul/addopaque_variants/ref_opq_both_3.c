#include <stdio.h>
static volatile int opq_326d = 7;
static volatile int opq_326d_b = 3;

#define N 8
int main(void) {
    if ((((opq_326d * opq_326d + opq_326d) % 2) == 0)) { opq_326d_b ^= 0; }
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_326d * opq_326d + opq_326d) % 2) == 0)) { opq_326d_b ^= 0; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_326d * opq_326d + opq_326d_b * opq_326d_b) % 4) == 3)) {
            { int jv_f622f = opq_326d ^ 0xC953;
                jv_f622f = (jv_f622f * 0x11) % 0x7FFFFFFF;
              (void)jv_f622f; }
        }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if ((((opq_326d * opq_326d + opq_326d_b * opq_326d_b) % 4) == 3)) {
        { int jv_d6e52 = opq_326d ^ 0xB92A;
            jv_d6e52 ^= (jv_d6e52 << 3) | 0xE513;
          (void)jv_d6e52; }
    }
    return 0;
}
