#include <stdio.h>
static volatile int opq_4815 = 7;
static volatile int opq_4815_b = 3;

#define N 8
int main(void) {
    if ((((opq_4815 * opq_4815 + opq_4815_b * opq_4815_b) % 4) == 3)) {
        { int jv_ef8fa = opq_4815 ^ 0xE629;
            jv_ef8fa ^= (jv_ef8fa << 3) | 0x2918;
          (void)jv_ef8fa; }
    }
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
        if ((((opq_4815 * opq_4815) % 4) == 2)) {
            { int jv_70974 = opq_4815 ^ 0x9BF4;
                jv_70974 ^= (jv_70974 << 3) | 0xD1BC;
                jv_70974 = (jv_70974 * 0x23) % 0x7FFFFFFF;
              (void)jv_70974; }
        }
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = 0;
    if ((((opq_4815 * opq_4815 + opq_4815_b * opq_4815_b) % 4) == 3)) {
        { int jv_ef231 = opq_4815 ^ 0xC37;
            jv_ef231 ^= (jv_ef231 << 3) | 0xE7D7;
            jv_ef231 += (jv_ef231 >> 2) + 0x91;
          (void)jv_ef231; }
    }
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_4815 * opq_4815) % 4) == 2)) {
        { int jv_9a135 = opq_4815 ^ 0x87E4;
            jv_9a135 = (jv_9a135 * 0x3D) % 0x7FFFFFFF;
            jv_9a135 += (jv_9a135 >> 2) + 0xF6;
            jv_9a135 ^= (jv_9a135 << 3) | 0xE622;
          (void)jv_9a135; }
    }
    printf("%ld\n", trace);
    return 0;
}
