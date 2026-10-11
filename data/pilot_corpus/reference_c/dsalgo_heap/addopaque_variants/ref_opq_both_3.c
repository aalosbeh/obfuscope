#include <stdio.h>
static volatile int opq_8e3c = 7;
static volatile int opq_8e3c_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    if ((((opq_8e3c * opq_8e3c + opq_8e3c) % 2) == 0)) { opq_8e3c_b ^= 0; }
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_8e3c * opq_8e3c + opq_8e3c) % 2) == 0)) { opq_8e3c_b ^= 0; }
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_8e3c * (opq_8e3c + 1)) % 2) == 0)) { opq_8e3c_b ^= 0; }
    h[0] = h[--hn];
    int i = 0;
    if (((opq_8e3c * opq_8e3c - opq_8e3c) % 2 == 0)) { opq_8e3c_b ^= 0; }
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if ((((opq_8e3c * opq_8e3c + opq_8e3c_b * opq_8e3c_b) % 4) == 3)) {
            { int jv_fafdb = opq_8e3c ^ 0x6A99;
                jv_fafdb = (jv_fafdb * 0x15) % 0x7FFFFFFF;
              (void)jv_fafdb; }
        }
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_8e3c * opq_8e3c + opq_8e3c_b * opq_8e3c_b) % 4) == 3)) {
            { int jv_63adb = opq_8e3c ^ 0x5700;
                jv_63adb += (jv_63adb >> 2) + 0x81;
                jv_63adb = (jv_63adb * 0x3B) % 0x7FFFFFFF;
                jv_63adb ^= (jv_63adb << 3) | 0xF81B;
              (void)jv_63adb; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_8e3c * (opq_8e3c + 1)) % 2) == 0)) { opq_8e3c_b ^= 0; }
        if (m == i) break;
        if ((((opq_8e3c * opq_8e3c + opq_8e3c_b * opq_8e3c_b) % 4) == 3)) {
            { int jv_97be1 = opq_8e3c ^ 0xA580;
                jv_97be1 += (jv_97be1 >> 2) + 0x23;
                jv_97be1 ^= (jv_97be1 << 3) | 0x7B76;
                jv_97be1 = (jv_97be1 * 0x37) % 0x7FFFFFFF;
              (void)jv_97be1; }
        }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
        if ((((opq_8e3c * opq_8e3c) % 4) == 2)) {
            { int jv_5209e = opq_8e3c ^ 0x2A01;
                jv_5209e += (jv_5209e >> 2) + 0x1F;
                jv_5209e = (jv_5209e * 0x20) % 0x7FFFFFFF;
                jv_5209e ^= (jv_5209e << 3) | 0xEB26;
              (void)jv_5209e; }
        }
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
