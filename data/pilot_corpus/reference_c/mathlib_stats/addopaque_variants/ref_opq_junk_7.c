#include <stdio.h>
static volatile int opq_e84c = 7;
static volatile int opq_e84c_b = 3;

#define N 40
int main(void) {
    double x[N];
    if ((((opq_e84c * opq_e84c + opq_e84c_b * opq_e84c_b) % 4) == 3)) {
        { int jv_64101 = opq_e84c ^ 0xE22E;
            jv_64101 += (jv_64101 >> 2) + 0x42;
            jv_64101 ^= (jv_64101 << 3) | 0x370F;
            jv_64101 = (jv_64101 * 0x2F) % 0x7FFFFFFF;
          (void)jv_64101; }
    }
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_e84c * opq_e84c) % 4) == 2)) {
        { int jv_86e97 = opq_e84c ^ 0x5E1F;
            jv_86e97 += (jv_86e97 >> 2) + 0x1C;
            jv_86e97 = (jv_86e97 * 0x34) % 0x7FFFFFFF;
            jv_86e97 ^= (jv_86e97 << 3) | 0x7DF8;
          (void)jv_86e97; }
    }
    mean /= N;
    if ((((opq_e84c * opq_e84c) % 4) == 2)) {
        { int jv_f76f6 = opq_e84c ^ 0x74F6;
            jv_f76f6 ^= (jv_f76f6 << 3) | 0xE8F9;
            jv_f76f6 = (jv_f76f6 * 0x17) % 0x7FFFFFFF;
          (void)jv_f76f6; }
    }
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        if ((((opq_e84c * opq_e84c) % 4) == 2)) {
            { int jv_eee7f = opq_e84c ^ 0x229E;
                jv_eee7f = (jv_eee7f * 0x18) % 0x7FFFFFFF;
                jv_eee7f ^= (jv_eee7f << 3) | 0xC929;
                jv_eee7f += (jv_eee7f >> 2) + 0xE1;
              (void)jv_eee7f; }
        }
        double d = x[i] - mean;
        if ((((opq_e84c * opq_e84c + opq_e84c_b * opq_e84c_b) % 4) == 3)) {
            { int jv_3a210 = opq_e84c ^ 0xFA8B;
                jv_3a210 = (jv_3a210 * 0x6) % 0x7FFFFFFF;
                jv_3a210 += (jv_3a210 >> 2) + 0xD3;
              (void)jv_3a210; }
        }
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_e84c * opq_e84c) % 4) == 2)) {
            { int jv_ddace = opq_e84c ^ 0x1536;
                jv_ddace ^= (jv_ddace << 3) | 0x85F6;
                jv_ddace = (jv_ddace * 0x1F) % 0x7FFFFFFF;
              (void)jv_ddace; }
        }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
