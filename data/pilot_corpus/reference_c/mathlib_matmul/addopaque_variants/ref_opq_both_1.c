#include <stdio.h>
static volatile int opq_52cf = 7;
static volatile int opq_52cf_b = 3;

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
        if ((((opq_52cf * opq_52cf + opq_52cf_b * opq_52cf_b) % 4) == 3)) {
            { int jv_f8bec = opq_52cf ^ 0x4E91;
                jv_f8bec = (jv_f8bec * 0x2F) % 0x7FFFFFFF;
                jv_f8bec ^= (jv_f8bec << 3) | 0x97CF;
                jv_f8bec += (jv_f8bec >> 2) + 0xF0;
              (void)jv_f8bec; }
        }
            int s = 0;
        if (((opq_52cf * opq_52cf - opq_52cf) % 2 == 0)) { opq_52cf_b ^= 0; }
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        if (((opq_52cf * opq_52cf - opq_52cf) % 2 == 0)) { opq_52cf_b ^= 0; }
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf("%ld\n", trace);
    if ((((opq_52cf * opq_52cf) % 4) == 2)) {
        { int jv_98f5e = opq_52cf ^ 0x5226;
            jv_98f5e = (jv_98f5e * 0x2D) % 0x7FFFFFFF;
            jv_98f5e += (jv_98f5e >> 2) + 0x2C;
          (void)jv_98f5e; }
    }
    return 0;
}
