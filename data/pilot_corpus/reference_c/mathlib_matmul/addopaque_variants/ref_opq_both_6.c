#include <stdio.h>
static volatile int opq_1f65 = 7;
static volatile int opq_1f65_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    if ((((opq_1f65 * opq_1f65 + opq_1f65_b * opq_1f65_b) % 4) == 3)) {
        { int jv_2bb6b = opq_1f65 ^ 0x6FEA;
            jv_2bb6b += (jv_2bb6b >> 2) + 0xC7;
          (void)jv_2bb6b; }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_1f65 * opq_1f65) % 4) == 2)) {
            { int jv_9e8f2 = opq_1f65 ^ 0x9FC7;
                jv_9e8f2 = (jv_9e8f2 * 0x11) % 0x7FFFFFFF;
                jv_9e8f2 ^= (jv_9e8f2 << 3) | 0x3412;
              (void)jv_9e8f2; }
        }
            c[i][j] = s;
        if (((opq_1f65 * opq_1f65 - opq_1f65) % 2 == 0)) { opq_1f65_b ^= 0; }
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if ((((opq_1f65 * opq_1f65) % 4) == 2)) {
        { int jv_6f717 = opq_1f65 ^ 0x7AAE;
            jv_6f717 ^= (jv_6f717 << 3) | 0x589A;
            jv_6f717 = (jv_6f717 * 0x2F) % 0x7FFFFFFF;
            jv_6f717 += (jv_6f717 >> 2) + 0x1C;
          (void)jv_6f717; }
    }
    return 0;
}
