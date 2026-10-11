#include <stdio.h>
static volatile int opq_35b2 = 7;
static volatile int opq_35b2_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    if ((((opq_35b2 * opq_35b2 + opq_35b2_b * opq_35b2_b) % 4) == 3)) {
        { int jv_8a378 = opq_35b2 ^ 0x64F7;
            jv_8a378 ^= (jv_8a378 << 3) | 0x9A2A;
          (void)jv_8a378; }
    }
    int i = hn++;
    if ((((opq_35b2 * opq_35b2) % 4) == 2)) {
        { int jv_57b39 = opq_35b2 ^ 0x6DDB;
            jv_57b39 = (jv_57b39 * 0x31) % 0x7FFFFFFF;
          (void)jv_57b39; }
    }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_35b2 * opq_35b2 + opq_35b2_b * opq_35b2_b) % 4) == 3)) {
            { int jv_6af30 = opq_35b2 ^ 0x2048;
                jv_6af30 = (jv_6af30 * 0x26) % 0x7FFFFFFF;
                jv_6af30 += (jv_6af30 >> 2) + 0x64;
                jv_6af30 ^= (jv_6af30 << 3) | 0x6047;
              (void)jv_6af30; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_35b2 * opq_35b2) % 4) == 2)) {
            { int jv_6603f = opq_35b2 ^ 0x1F2A;
                jv_6603f = (jv_6603f * 0x1A) % 0x7FFFFFFF;
                jv_6603f += (jv_6603f >> 2) + 0x1C;
              (void)jv_6603f; }
        }
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_35b2 * opq_35b2) % 4) == 2)) {
        { int jv_cbf7d = opq_35b2 ^ 0x16A6;
            jv_cbf7d = (jv_cbf7d * 0x3D) % 0x7FFFFFFF;
            jv_cbf7d ^= (jv_cbf7d << 3) | 0x2FC3;
          (void)jv_cbf7d; }
    }
    h[0] = h[--hn];
    if ((((opq_35b2 * opq_35b2 + opq_35b2_b * opq_35b2_b) % 4) == 3)) {
        { int jv_44682 = opq_35b2 ^ 0xD089;
            jv_44682 += (jv_44682 >> 2) + 0x43;
            jv_44682 ^= (jv_44682 << 3) | 0x6B26;
            jv_44682 = (jv_44682 * 0x1A) % 0x7FFFFFFF;
          (void)jv_44682; }
    }
    int i = 0;
    if ((((opq_35b2 * opq_35b2) % 4) == 2)) {
        { int jv_f8282 = opq_35b2 ^ 0xA92D;
            jv_f8282 ^= (jv_f8282 << 3) | 0xC7B;
          (void)jv_f8282; }
    }
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if ((((opq_35b2 * opq_35b2 + opq_35b2_b * opq_35b2_b) % 4) == 3)) {
            { int jv_69b18 = opq_35b2 ^ 0xA403;
                jv_69b18 += (jv_69b18 >> 2) + 0xD1;
                jv_69b18 = (jv_69b18 * 0x31) % 0x7FFFFFFF;
              (void)jv_69b18; }
        }
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_35b2 * opq_35b2) % 4) == 2)) {
            { int jv_3be1d = opq_35b2 ^ 0x4D79;
                jv_3be1d += (jv_3be1d >> 2) + 0xCF;
                jv_3be1d ^= (jv_3be1d << 3) | 0x5896;
                jv_3be1d = (jv_3be1d * 0x28) % 0x7FFFFFFF;
              (void)jv_3be1d; }
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
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
