#include <stdio.h>
static volatile int opq_33f6 = 7;
static volatile int opq_33f6_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_33f6 * opq_33f6) % 4) == 2)) {
            { int jv_b6a4f = opq_33f6 ^ 0xCCD9;
                jv_b6a4f ^= (jv_b6a4f << 3) | 0x40A7;
                jv_b6a4f += (jv_b6a4f >> 2) + 0xA2;
              (void)jv_b6a4f; }
        }
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_33f6 * opq_33f6 + opq_33f6_b * opq_33f6_b) % 4) == 3)) {
        { int jv_cdcb4 = opq_33f6 ^ 0x63B4;
            jv_cdcb4 ^= (jv_cdcb4 << 3) | 0x4009;
            jv_cdcb4 = (jv_cdcb4 * 0x3B) % 0x7FFFFFFF;
            jv_cdcb4 += (jv_cdcb4 >> 2) + 0x11;
          (void)jv_cdcb4; }
    }
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        if ((((opq_33f6 * opq_33f6 + opq_33f6_b * opq_33f6_b) % 4) == 3)) {
            { int jv_cf8d2 = opq_33f6 ^ 0x8D0E;
                jv_cf8d2 = (jv_cf8d2 * 0x28) % 0x7FFFFFFF;
                jv_cf8d2 ^= (jv_cf8d2 << 3) | 0x32FD;
                jv_cf8d2 += (jv_cf8d2 >> 2) + 0xDA;
              (void)jv_cf8d2; }
        }
        int l = 2 * i + 1, r = l + 1, m = i;
        if ((((opq_33f6 * opq_33f6 + opq_33f6_b * opq_33f6_b) % 4) == 3)) {
            { int jv_6f965 = opq_33f6 ^ 0xD41C;
                jv_6f965 = (jv_6f965 * 0x28) % 0x7FFFFFFF;
              (void)jv_6f965; }
        }
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_33f6 * opq_33f6 + opq_33f6_b * opq_33f6_b) % 4) == 3)) {
            { int jv_d2c3c = opq_33f6 ^ 0x2662;
                jv_d2c3c += (jv_d2c3c >> 2) + 0xC7;
              (void)jv_d2c3c; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        if ((((opq_33f6 * opq_33f6) % 4) == 2)) {
            { int jv_c4347 = opq_33f6 ^ 0x684C;
                jv_c4347 ^= (jv_c4347 << 3) | 0x9038;
              (void)jv_c4347; }
        }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_33f6 * opq_33f6) % 4) == 2)) {
        { int jv_6bce5 = opq_33f6 ^ 0xEF8;
            jv_6bce5 ^= (jv_6bce5 << 3) | 0x1060;
            jv_6bce5 += (jv_6bce5 >> 2) + 0xBE;
            jv_6bce5 = (jv_6bce5 * 0x2C) % 0x7FFFFFFF;
          (void)jv_6bce5; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_33f6 * opq_33f6 + opq_33f6_b * opq_33f6_b) % 4) == 3)) {
        { int jv_52a08 = opq_33f6 ^ 0xED7E;
            jv_52a08 ^= (jv_52a08 << 3) | 0x13D4;
            jv_52a08 += (jv_52a08 >> 2) + 0xE8;
          (void)jv_52a08; }
    }
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_33f6 * opq_33f6 + opq_33f6_b * opq_33f6_b) % 4) == 3)) {
        { int jv_56f3d = opq_33f6 ^ 0xCB02;
            jv_56f3d ^= (jv_56f3d << 3) | 0x613F;
          (void)jv_56f3d; }
    }
    return 0;
}
