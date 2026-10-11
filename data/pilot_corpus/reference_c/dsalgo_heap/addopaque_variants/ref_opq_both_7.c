#include <stdio.h>
static volatile int opq_c77b = 7;
static volatile int opq_c77b_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if ((((opq_c77b * opq_c77b) % 4) == 2)) {
        { int jv_7157f = opq_c77b ^ 0x2BEF;
            jv_7157f = (jv_7157f * 0x19) % 0x7FFFFFFF;
            jv_7157f ^= (jv_7157f << 3) | 0x1573;
          (void)jv_7157f; }
    }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if ((((opq_c77b * opq_c77b) % 4) == 2)) {
            { int jv_8501b = opq_c77b ^ 0x279D;
                jv_8501b ^= (jv_8501b << 3) | 0x9176;
                jv_8501b += (jv_8501b >> 2) + 0x15;
              (void)jv_8501b; }
        }
        if (h[p] <= h[i]) break;
        if ((((opq_c77b * opq_c77b + opq_c77b_b * opq_c77b_b) % 4) == 3)) {
            { int jv_6ca8f = opq_c77b ^ 0x93BB;
                jv_6ca8f ^= (jv_6ca8f << 3) | 0x8274;
              (void)jv_6ca8f; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    if (((opq_c77b * opq_c77b - opq_c77b) % 2 == 0)) { opq_c77b_b ^= 0; }
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        if ((((opq_c77b * opq_c77b + opq_c77b) % 2) == 0)) { opq_c77b_b ^= 0; }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_c77b * opq_c77b + opq_c77b_b * opq_c77b_b) % 4) == 3)) {
            { int jv_172c0 = opq_c77b ^ 0x2CAF;
                jv_172c0 ^= (jv_172c0 << 3) | 0xEABB;
              (void)jv_172c0; }
        }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_c77b * opq_c77b + opq_c77b_b * opq_c77b_b) % 4) == 3)) {
        { int jv_4d037 = opq_c77b ^ 0xA687;
            jv_4d037 += (jv_4d037 >> 2) + 0x84;
            jv_4d037 ^= (jv_4d037 << 3) | 0x6DBA;
            jv_4d037 = (jv_4d037 * 0x28) % 0x7FFFFFFF;
          (void)jv_4d037; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_c77b * opq_c77b) % 4) == 2)) {
        { int jv_d93e0 = opq_c77b ^ 0x6148;
            jv_d93e0 += (jv_d93e0 >> 2) + 0xDA;
            jv_d93e0 = (jv_d93e0 * 0x2B) % 0x7FFFFFFF;
          (void)jv_d93e0; }
    }
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_c77b * opq_c77b) % 4) == 2)) {
        { int jv_c791e = opq_c77b ^ 0xE3C8;
            jv_c791e ^= (jv_c791e << 3) | 0xAB20;
            jv_c791e = (jv_c791e * 0x2B) % 0x7FFFFFFF;
          (void)jv_c791e; }
    }
    return 0;
}
