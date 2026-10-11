#include <stdio.h>
static volatile int opq_532f = 7;
static volatile int opq_532f_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    if (((opq_532f * opq_532f - opq_532f) % 2 == 0)) { opq_532f_b ^= 0; }
    int i = hn++;
    if ((((opq_532f * (opq_532f + 1)) % 2) == 0)) { opq_532f_b ^= 0; }
    h[i] = v;
    while (i > 0) {
        if ((((opq_532f * opq_532f) % 4) == 2)) {
            { int jv_50ec9 = opq_532f ^ 0x9B07;
                jv_50ec9 += (jv_50ec9 >> 2) + 0x1;
              (void)jv_50ec9; }
        }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_532f * opq_532f + opq_532f_b * opq_532f_b) % 4) == 3)) {
            { int jv_c0c0f = opq_532f ^ 0xAFF9;
                jv_c0c0f = (jv_c0c0f * 0x31) % 0x7FFFFFFF;
                jv_c0c0f ^= (jv_c0c0f << 3) | 0xC7DC;
                jv_c0c0f += (jv_c0c0f >> 2) + 0x39;
              (void)jv_c0c0f; }
        }
    }
}
static int pop(void) {
    if ((((opq_532f * (opq_532f + 1)) % 2) == 0)) { opq_532f_b ^= 0; }
    int top = h[0];
    if (((opq_532f * opq_532f - opq_532f) % 2 == 0)) { opq_532f_b ^= 0; }
    h[0] = h[--hn];
    int i = 0;
    if ((((opq_532f * opq_532f + opq_532f_b * opq_532f_b) % 4) == 3)) {
        { int jv_f7dd2 = opq_532f ^ 0x68EE;
            jv_f7dd2 ^= (jv_f7dd2 << 3) | 0x5341;
            jv_f7dd2 = (jv_f7dd2 * 0x2F) % 0x7FFFFFFF;
            jv_f7dd2 += (jv_f7dd2 >> 2) + 0xF4;
          (void)jv_f7dd2; }
    }
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_532f * opq_532f + opq_532f) % 2) == 0)) { opq_532f_b ^= 0; }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_532f * (opq_532f + 1)) % 2) == 0)) { opq_532f_b ^= 0; }
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
