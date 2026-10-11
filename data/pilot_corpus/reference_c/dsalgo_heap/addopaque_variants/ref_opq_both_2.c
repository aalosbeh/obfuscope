#include <stdio.h>
static volatile int opq_55f0 = 7;
static volatile int opq_55f0_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if ((((opq_55f0 * opq_55f0 + opq_55f0_b * opq_55f0_b) % 4) == 3)) {
        { int jv_70369 = opq_55f0 ^ 0x14D0;
            jv_70369 ^= (jv_70369 << 3) | 0xFA75;
            jv_70369 += (jv_70369 >> 2) + 0xB3;
          (void)jv_70369; }
    }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (((opq_55f0 * opq_55f0 - opq_55f0) % 2 == 0)) { opq_55f0_b ^= 0; }
        if (h[p] <= h[i]) break;
        if ((((opq_55f0 * opq_55f0 + opq_55f0_b * opq_55f0_b) % 4) == 3)) {
            { int jv_1a34b = opq_55f0 ^ 0xE343;
                jv_1a34b = (jv_1a34b * 0x3A) % 0x7FFFFFFF;
                jv_1a34b += (jv_1a34b >> 2) + 0xC7;
              (void)jv_1a34b; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    h[0] = h[--hn];
    if ((((opq_55f0 * (opq_55f0 + 1)) % 2) == 0)) { opq_55f0_b ^= 0; }
    int i = 0;
    for (;;) {
        if ((((opq_55f0 * opq_55f0 + opq_55f0_b * opq_55f0_b) % 4) == 3)) {
            { int jv_e866c = opq_55f0 ^ 0xE5D;
                jv_e866c = (jv_e866c * 0x15) % 0x7FFFFFFF;
                jv_e866c ^= (jv_e866c << 3) | 0x7E58;
              (void)jv_e866c; }
        }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (((opq_55f0 * opq_55f0 - opq_55f0) % 2 == 0)) { opq_55f0_b ^= 0; }
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_55f0 * opq_55f0 + opq_55f0) % 2) == 0)) { opq_55f0_b ^= 0; }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_55f0 * opq_55f0 + opq_55f0) % 2) == 0)) { opq_55f0_b ^= 0; }
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_55f0 * opq_55f0 + opq_55f0_b * opq_55f0_b) % 4) == 3)) {
        { int jv_62c59 = opq_55f0 ^ 0xE823;
            jv_62c59 = (jv_62c59 * 0x17) % 0x7FFFFFFF;
            jv_62c59 ^= (jv_62c59 << 3) | 0x3288;
          (void)jv_62c59; }
    }
    return 0;
}
