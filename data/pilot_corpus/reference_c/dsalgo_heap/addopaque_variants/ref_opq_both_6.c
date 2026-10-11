#include <stdio.h>
static volatile int opq_50cc = 7;
static volatile int opq_50cc_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if (((opq_50cc * opq_50cc - opq_50cc) % 2 == 0)) { opq_50cc_b ^= 0; }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_50cc * opq_50cc + opq_50cc_b * opq_50cc_b) % 4) == 3)) {
            { int jv_84020 = opq_50cc ^ 0x4ABE;
                jv_84020 ^= (jv_84020 << 3) | 0x6C1D;
                jv_84020 += (jv_84020 >> 2) + 0xDF;
              (void)jv_84020; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        if ((((opq_50cc * opq_50cc + opq_50cc) % 2) == 0)) { opq_50cc_b ^= 0; }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_50cc * opq_50cc + opq_50cc_b * opq_50cc_b) % 4) == 3)) {
            { int jv_a600b = opq_50cc ^ 0xE8E7;
                jv_a600b += (jv_a600b >> 2) + 0x95;
              (void)jv_a600b; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_50cc * opq_50cc + opq_50cc_b * opq_50cc_b) % 4) == 3)) {
            { int jv_d017b = opq_50cc ^ 0x1CF9;
                jv_d017b += (jv_d017b >> 2) + 0x59;
              (void)jv_d017b; }
        }
        if (m == i) break;
        if ((((opq_50cc * (opq_50cc + 1)) % 2) == 0)) { opq_50cc_b ^= 0; }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
        if ((((opq_50cc * opq_50cc + opq_50cc_b * opq_50cc_b) % 4) == 3)) {
            { int jv_b5e46 = opq_50cc ^ 0x5E44;
                jv_b5e46 = (jv_b5e46 * 0x28) % 0x7FFFFFFF;
              (void)jv_b5e46; }
        }
    }
    return top;
}
int main(void) {
    if (((opq_50cc * opq_50cc - opq_50cc) % 2 == 0)) { opq_50cc_b ^= 0; }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    if (((opq_50cc * opq_50cc - opq_50cc) % 2 == 0)) { opq_50cc_b ^= 0; }
    return 0;
}
