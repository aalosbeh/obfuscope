#include <stdio.h>
static volatile int opq_738a = 7;
static volatile int opq_738a_b = 3;

#define N 8
int main(void) {
    if (((opq_738a * opq_738a - opq_738a) % 2 == 0)) { opq_738a_b ^= 0; }
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
        if ((((opq_738a * opq_738a + opq_738a) % 2) == 0)) { opq_738a_b ^= 0; }
            c[i][j] = s;
        if ((((opq_738a * (opq_738a + 1)) % 2) == 0)) { opq_738a_b ^= 0; }
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    if ((((opq_738a * opq_738a + opq_738a_b * opq_738a_b) % 4) == 3)) {
        { int jv_9b130 = opq_738a ^ 0xD63E;
            jv_9b130 ^= (jv_9b130 << 3) | 0xEB4D;
            jv_9b130 = (jv_9b130 * 0xF) % 0x7FFFFFFF;
            jv_9b130 += (jv_9b130 >> 2) + 0x55;
          (void)jv_9b130; }
    }
    printf("%ld\n", trace);
    return 0;
}
