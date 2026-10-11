#include <stdio.h>
static volatile int opq_d8d8 = 7;
static volatile int opq_d8d8_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    if ((((opq_d8d8 * opq_d8d8 + opq_d8d8_b * opq_d8d8_b) % 4) == 3)) {
        { int jv_e45a3 = opq_d8d8 ^ 0x9A62;
            jv_e45a3 ^= (jv_e45a3 << 3) | 0x1AE8;
            jv_e45a3 = (jv_e45a3 * 0x21) % 0x7FFFFFFF;
            jv_e45a3 += (jv_e45a3 >> 2) + 0xB8;
          (void)jv_e45a3; }
    }
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        if ((((opq_d8d8 * opq_d8d8) % 4) == 2)) {
            { int jv_66904 = opq_d8d8 ^ 0x27DD;
                jv_66904 ^= (jv_66904 << 3) | 0x7AD7;
              (void)jv_66904; }
        }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_d8d8 * (opq_d8d8 + 1)) % 2) == 0)) { opq_d8d8_b ^= 0; }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_d8d8 * (opq_d8d8 + 1)) % 2) == 0)) { opq_d8d8_b ^= 0; }
    }
}
static int pop(void) {
    if ((((opq_d8d8 * opq_d8d8) % 4) == 2)) {
        { int jv_e241e = opq_d8d8 ^ 0x2C47;
            jv_e241e += (jv_e241e >> 2) + 0xE9;
            jv_e241e = (jv_e241e * 0x9) % 0x7FFFFFFF;
            jv_e241e ^= (jv_e241e << 3) | 0xFEBC;
          (void)jv_e241e; }
    }
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        if ((((opq_d8d8 * opq_d8d8) % 4) == 2)) {
            { int jv_cbe25 = opq_d8d8 ^ 0x10A9;
                jv_cbe25 = (jv_cbe25 * 0x37) % 0x7FFFFFFF;
                jv_cbe25 += (jv_cbe25 >> 2) + 0xF8;
                jv_cbe25 ^= (jv_cbe25 << 3) | 0x1620;
              (void)jv_cbe25; }
        }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_d8d8 * (opq_d8d8 + 1)) % 2) == 0)) { opq_d8d8_b ^= 0; }
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_d8d8 * opq_d8d8) % 4) == 2)) {
            { int jv_d4d51 = opq_d8d8 ^ 0x5E3E;
                jv_d4d51 += (jv_d4d51 >> 2) + 0xC9;
              (void)jv_d4d51; }
        }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_d8d8 * opq_d8d8 + opq_d8d8_b * opq_d8d8_b) % 4) == 3)) {
        { int jv_e8df7 = opq_d8d8 ^ 0x6EEE;
            jv_e8df7 += (jv_e8df7 >> 2) + 0xBD;
          (void)jv_e8df7; }
    }
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
