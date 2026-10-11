#include <stdio.h>
static volatile int opq_1270 = 7;
static volatile int opq_1270_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
            { int jv_1fa71 = opq_1270 ^ 0x77C0;
                jv_1fa71 = (jv_1fa71 * 0xD) % 0x7FFFFFFF;
              (void)jv_1fa71; }
        }
    }
}
static int pop(void) {
    if ((((opq_1270 * opq_1270) % 4) == 2)) {
        { int jv_febc6 = opq_1270 ^ 0xE1D4;
            jv_febc6 += (jv_febc6 >> 2) + 0x20;
            jv_febc6 ^= (jv_febc6 << 3) | 0x9A42;
          (void)jv_febc6; }
    }
    int top = h[0];
    if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
        { int jv_a9561 = opq_1270 ^ 0x43D0;
            jv_a9561 ^= (jv_a9561 << 3) | 0x681B;
            jv_a9561 = (jv_a9561 * 0x20) % 0x7FFFFFFF;
          (void)jv_a9561; }
    }
    h[0] = h[--hn];
    if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
        { int jv_34117 = opq_1270 ^ 0xC0E2;
            jv_34117 = (jv_34117 * 0xB) % 0x7FFFFFFF;
            jv_34117 += (jv_34117 >> 2) + 0x50;
            jv_34117 ^= (jv_34117 << 3) | 0x290B;
          (void)jv_34117; }
    }
    int i = 0;
    for (;;) {
        if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
            { int jv_50e80 = opq_1270 ^ 0x2F9F;
                jv_50e80 = (jv_50e80 * 0xA) % 0x7FFFFFFF;
                jv_50e80 += (jv_50e80 >> 2) + 0xDC;
              (void)jv_50e80; }
        }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
            { int jv_7aca0 = opq_1270 ^ 0x6774;
                jv_7aca0 = (jv_7aca0 * 0x25) % 0x7FFFFFFF;
              (void)jv_7aca0; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_1270 * opq_1270) % 4) == 2)) {
            { int jv_e7ccf = opq_1270 ^ 0xD844;
                jv_e7ccf ^= (jv_e7ccf << 3) | 0x9B13;
                jv_e7ccf += (jv_e7ccf >> 2) + 0x58;
              (void)jv_e7ccf; }
        }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
        { int jv_13dc8 = opq_1270 ^ 0xB7FC;
            jv_13dc8 = (jv_13dc8 * 0x6) % 0x7FFFFFFF;
            jv_13dc8 += (jv_13dc8 >> 2) + 0x51;
          (void)jv_13dc8; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_1270 * opq_1270 + opq_1270_b * opq_1270_b) % 4) == 3)) {
        { int jv_71643 = opq_1270 ^ 0x737D;
            jv_71643 = (jv_71643 * 0x23) % 0x7FFFFFFF;
            jv_71643 += (jv_71643 >> 2) + 0x22;
          (void)jv_71643; }
    }
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
