#include <stdio.h>
static volatile int opq_6fad = 7;
static volatile int opq_6fad_b = 3;

#define N 8
int main(void) {
    if ((((opq_6fad * opq_6fad + opq_6fad_b * opq_6fad_b) % 4) == 3)) {
        { int jv_7a65b = opq_6fad ^ 0xA143;
            jv_7a65b ^= (jv_7a65b << 3) | 0xCA45;
            jv_7a65b = (jv_7a65b * 0x34) % 0x7FFFFFFF;
            jv_7a65b += (jv_7a65b >> 2) + 0xE;
          (void)jv_7a65b; }
    }
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_6fad * opq_6fad + opq_6fad) % 2) == 0)) { opq_6fad_b ^= 0; }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_6fad * opq_6fad + opq_6fad) % 2) == 0)) { opq_6fad_b ^= 0; }
            c[i][j] = s;
        }
    long trace = 0;
    if ((((opq_6fad * (opq_6fad + 1)) % 2) == 0)) { opq_6fad_b ^= 0; }
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    return 0;
}
