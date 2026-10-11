#include <stdio.h>
static volatile int opq_8d71 = 7;
static volatile int opq_8d71_b = 3;

#define N 40
int main(void) {
    if ((((opq_8d71 * opq_8d71) % 4) == 2)) {
        { int jv_9e552 = opq_8d71 ^ 0xAF19;
            jv_9e552 = (jv_9e552 * 0x27) % 0x7FFFFFFF;
            jv_9e552 ^= (jv_9e552 << 3) | 0x2002;
            jv_9e552 += (jv_9e552 >> 2) + 0x59;
          (void)jv_9e552; }
    }
    double x[N];
    unsigned s = 11;
    if ((((opq_8d71 * opq_8d71) % 4) == 2)) {
        { int jv_9d8dc = opq_8d71 ^ 0x310;
            jv_9d8dc += (jv_9d8dc >> 2) + 0xDC;
          (void)jv_9d8dc; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if ((((opq_8d71 * opq_8d71) % 4) == 2)) {
        { int jv_8a69b = opq_8d71 ^ 0xBAA4;
            jv_8a69b = (jv_8a69b * 0x2A) % 0x7FFFFFFF;
            jv_8a69b ^= (jv_8a69b << 3) | 0xDE4F;
            jv_8a69b += (jv_8a69b >> 2) + 0x1C;
          (void)jv_8a69b; }
    }
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_8d71 * opq_8d71) % 4) == 2)) {
        { int jv_b32d8 = opq_8d71 ^ 0xDEE1;
            jv_b32d8 ^= (jv_b32d8 << 3) | 0x201C;
            jv_b32d8 = (jv_b32d8 * 0x19) % 0x7FFFFFFF;
            jv_b32d8 += (jv_b32d8 >> 2) + 0x10;
          (void)jv_b32d8; }
    }
    mean /= N;
    if ((((opq_8d71 * opq_8d71 + opq_8d71_b * opq_8d71_b) % 4) == 3)) {
        { int jv_be0f8 = opq_8d71 ^ 0x7D44;
            jv_be0f8 ^= (jv_be0f8 << 3) | 0x95E1;
            jv_be0f8 += (jv_be0f8 >> 2) + 0xBB;
          (void)jv_be0f8; }
    }
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_8d71 * opq_8d71 + opq_8d71_b * opq_8d71_b) % 4) == 3)) {
            { int jv_dff62 = opq_8d71 ^ 0x9BAB;
                jv_dff62 = (jv_dff62 * 0x4) % 0x7FFFFFFF;
                jv_dff62 += (jv_dff62 >> 2) + 0xB9;
                jv_dff62 ^= (jv_dff62 << 3) | 0xC509;
              (void)jv_dff62; }
        }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
