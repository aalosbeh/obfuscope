#include <stdio.h>
static volatile int opq_a130 = 7;
static volatile int opq_a130_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_a130 * (opq_a130 + 1)) % 2) == 0)) { opq_a130_b ^= 0; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_a130 * opq_a130 + opq_a130_b * opq_a130_b) % 4) == 3)) {
            { int jv_87ba6 = opq_a130 ^ 0x7538;
                jv_87ba6 += (jv_87ba6 >> 2) + 0xF2;
                jv_87ba6 ^= (jv_87ba6 << 3) | 0x6772;
                jv_87ba6 = (jv_87ba6 * 0x29) % 0x7FFFFFFF;
              (void)jv_87ba6; }
        }
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_a130 * opq_a130 + opq_a130) % 2) == 0)) { opq_a130_b ^= 0; }
            c[i][j] = s;
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_a130 * opq_a130 + opq_a130_b * opq_a130_b) % 4) == 3)) {
        { int jv_6bb87 = opq_a130 ^ 0xF8C6;
            jv_6bb87 = (jv_6bb87 * 0x2C) % 0x7FFFFFFF;
          (void)jv_6bb87; }
    }
    printf("%ld\n", trace);
    return 0;
}
