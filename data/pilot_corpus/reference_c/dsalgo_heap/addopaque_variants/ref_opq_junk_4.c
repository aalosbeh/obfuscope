#include <stdio.h>
static volatile int opq_afb7 = 7;
static volatile int opq_afb7_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        if ((((opq_afb7 * opq_afb7) % 4) == 2)) {
            { int jv_1d268 = opq_afb7 ^ 0x8FA9;
                jv_1d268 ^= (jv_1d268 << 3) | 0xB245;
                jv_1d268 = (jv_1d268 * 0x3B) % 0x7FFFFFFF;
              (void)jv_1d268; }
        }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_afb7 * opq_afb7) % 4) == 2)) {
            { int jv_fdf23 = opq_afb7 ^ 0x8BCA;
                jv_fdf23 ^= (jv_fdf23 << 3) | 0x5482;
              (void)jv_fdf23; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_afb7 * opq_afb7 + opq_afb7_b * opq_afb7_b) % 4) == 3)) {
            { int jv_654c6 = opq_afb7 ^ 0x63D5;
                jv_654c6 ^= (jv_654c6 << 3) | 0xFB78;
                jv_654c6 = (jv_654c6 * 0x6) % 0x7FFFFFFF;
              (void)jv_654c6; }
        }
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_afb7 * opq_afb7 + opq_afb7_b * opq_afb7_b) % 4) == 3)) {
        { int jv_dd2d7 = opq_afb7 ^ 0xDF04;
            jv_dd2d7 += (jv_dd2d7 >> 2) + 0xE;
            jv_dd2d7 = (jv_dd2d7 * 0x1A) % 0x7FFFFFFF;
          (void)jv_dd2d7; }
    }
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if ((((opq_afb7 * opq_afb7) % 4) == 2)) {
            { int jv_c83b6 = opq_afb7 ^ 0x4B91;
                jv_c83b6 += (jv_c83b6 >> 2) + 0xA8;
              (void)jv_c83b6; }
        }
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_afb7 * opq_afb7) % 4) == 2)) {
            { int jv_df35a = opq_afb7 ^ 0x2DBA;
                jv_df35a += (jv_df35a >> 2) + 0x4;
                jv_df35a = (jv_df35a * 0x1E) % 0x7FFFFFFF;
                jv_df35a ^= (jv_df35a << 3) | 0xC6E6;
              (void)jv_df35a; }
        }
        if (m == i) break;
        if ((((opq_afb7 * opq_afb7 + opq_afb7_b * opq_afb7_b) % 4) == 3)) {
            { int jv_6cd50 = opq_afb7 ^ 0x385A;
                jv_6cd50 ^= (jv_6cd50 << 3) | 0xEA1F;
                jv_6cd50 = (jv_6cd50 * 0x2B) % 0x7FFFFFFF;
                jv_6cd50 += (jv_6cd50 >> 2) + 0x6A;
              (void)jv_6cd50; }
        }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
        if ((((opq_afb7 * opq_afb7 + opq_afb7_b * opq_afb7_b) % 4) == 3)) {
            { int jv_21694 = opq_afb7 ^ 0x21DD;
                jv_21694 = (jv_21694 * 0x1A) % 0x7FFFFFFF;
                jv_21694 ^= (jv_21694 << 3) | 0x24C0;
                jv_21694 += (jv_21694 >> 2) + 0xFE;
              (void)jv_21694; }
        }
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_afb7 * opq_afb7 + opq_afb7_b * opq_afb7_b) % 4) == 3)) {
        { int jv_d5616 = opq_afb7 ^ 0xA0FF;
            jv_d5616 = (jv_d5616 * 0x39) % 0x7FFFFFFF;
            jv_d5616 += (jv_d5616 >> 2) + 0x88;
          (void)jv_d5616; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
