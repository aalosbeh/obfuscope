#include <stdio.h>
static volatile int opq_fe0c = 7;
static volatile int opq_fe0c_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if ((((opq_fe0c * opq_fe0c + opq_fe0c_b * opq_fe0c_b) % 4) == 3)) {
        { int jv_2bb7f = opq_fe0c ^ 0x3602;
            jv_2bb7f ^= (jv_2bb7f << 3) | 0x2B59;
            jv_2bb7f += (jv_2bb7f >> 2) + 0x39;
            jv_2bb7f = (jv_2bb7f * 0x22) % 0x7FFFFFFF;
          (void)jv_2bb7f; }
    }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if ((((opq_fe0c * opq_fe0c + opq_fe0c_b * opq_fe0c_b) % 4) == 3)) {
            { int jv_88842 = opq_fe0c ^ 0x96AA;
                jv_88842 += (jv_88842 >> 2) + 0x5E;
                jv_88842 ^= (jv_88842 << 3) | 0xBAC3;
                jv_88842 = (jv_88842 * 0xA) % 0x7FFFFFFF;
              (void)jv_88842; }
        }
        if (h[p] <= h[i]) break;
        if ((((opq_fe0c * opq_fe0c + opq_fe0c_b * opq_fe0c_b) % 4) == 3)) {
            { int jv_9169c = opq_fe0c ^ 0xA9D9;
                jv_9169c = (jv_9169c * 0x5) % 0x7FFFFFFF;
              (void)jv_9169c; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_fe0c * opq_fe0c + opq_fe0c_b * opq_fe0c_b) % 4) == 3)) {
        { int jv_b311e = opq_fe0c ^ 0xDC0A;
            jv_b311e = (jv_b311e * 0x24) % 0x7FFFFFFF;
            jv_b311e += (jv_b311e >> 2) + 0xCF;
          (void)jv_b311e; }
    }
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if ((((opq_fe0c * opq_fe0c + opq_fe0c_b * opq_fe0c_b) % 4) == 3)) {
            { int jv_d0f99 = opq_fe0c ^ 0x96E0;
                jv_d0f99 += (jv_d0f99 >> 2) + 0x59;
              (void)jv_d0f99; }
        }
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_fe0c * opq_fe0c) % 4) == 2)) {
            { int jv_d66f9 = opq_fe0c ^ 0xA70D;
                jv_d66f9 += (jv_d66f9 >> 2) + 0x6A;
                jv_d66f9 = (jv_d66f9 * 0x19) % 0x7FFFFFFF;
                jv_d66f9 ^= (jv_d66f9 << 3) | 0xAFF1;
              (void)jv_d66f9; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
        if ((((opq_fe0c * opq_fe0c) % 4) == 2)) {
            { int jv_ea965 = opq_fe0c ^ 0x8BFC;
                jv_ea965 += (jv_ea965 >> 2) + 0x58;
                jv_ea965 ^= (jv_ea965 << 3) | 0x8BE6;
              (void)jv_ea965; }
        }
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_fe0c * opq_fe0c) % 4) == 2)) {
        { int jv_11c02 = opq_fe0c ^ 0xA8E8;
            jv_11c02 ^= (jv_11c02 << 3) | 0x189B;
            jv_11c02 = (jv_11c02 * 0x1B) % 0x7FFFFFFF;
            jv_11c02 += (jv_11c02 >> 2) + 0xD6;
          (void)jv_11c02; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_fe0c * opq_fe0c) % 4) == 2)) {
        { int jv_2e344 = opq_fe0c ^ 0x229;
            jv_2e344 ^= (jv_2e344 << 3) | 0xEE1F;
          (void)jv_2e344; }
    }
    return 0;
}
