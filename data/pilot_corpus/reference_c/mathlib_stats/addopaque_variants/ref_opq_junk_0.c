#include <stdio.h>
static volatile int opq_1fbd = 7;
static volatile int opq_1fbd_b = 3;

#define N 40
int main(void) {
    if ((((opq_1fbd * opq_1fbd) % 4) == 2)) {
        { int jv_eef82 = opq_1fbd ^ 0x6E75;
            jv_eef82 ^= (jv_eef82 << 3) | 0x9C6A;
            jv_eef82 += (jv_eef82 >> 2) + 0x3C;
          (void)jv_eef82; }
    }
    double x[N];
    unsigned s = 11;
    if ((((opq_1fbd * opq_1fbd) % 4) == 2)) {
        { int jv_daa95 = opq_1fbd ^ 0x284;
            jv_daa95 = (jv_daa95 * 0x3) % 0x7FFFFFFF;
            jv_daa95 ^= (jv_daa95 << 3) | 0xC98F;
          (void)jv_daa95; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        if ((((opq_1fbd * opq_1fbd) % 4) == 2)) {
            { int jv_8f352 = opq_1fbd ^ 0x8FCC;
                jv_8f352 += (jv_8f352 >> 2) + 0x98;
              (void)jv_8f352; }
        }
        double d = x[i] - mean;
        var += d * d;
        if ((((opq_1fbd * opq_1fbd + opq_1fbd_b * opq_1fbd_b) % 4) == 3)) {
            { int jv_ae7dc = opq_1fbd ^ 0x867B;
                jv_ae7dc ^= (jv_ae7dc << 3) | 0xE40D;
                jv_ae7dc += (jv_ae7dc >> 2) + 0xE3;
              (void)jv_ae7dc; }
        }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_1fbd * opq_1fbd + opq_1fbd_b * opq_1fbd_b) % 4) == 3)) {
            { int jv_7be52 = opq_1fbd ^ 0xB24B;
                jv_7be52 = (jv_7be52 * 0x27) % 0x7FFFFFFF;
                jv_7be52 ^= (jv_7be52 << 3) | 0xC2DD;
                jv_7be52 += (jv_7be52 >> 2) + 0x16;
              (void)jv_7be52; }
        }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_1fbd * opq_1fbd) % 4) == 2)) {
        { int jv_13a80 = opq_1fbd ^ 0xAEF;
            jv_13a80 += (jv_13a80 >> 2) + 0x5;
            jv_13a80 ^= (jv_13a80 << 3) | 0xF9D1;
          (void)jv_13a80; }
    }
    return 0;
}
