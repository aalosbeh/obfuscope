#include <stdio.h>
static volatile int opq_670e = 7;
static volatile int opq_670e_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
            { int jv_45ef1 = opq_670e ^ 0x2412;
                jv_45ef1 = (jv_45ef1 * 0x26) % 0x7FFFFFFF;
              (void)jv_45ef1; }
        }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
        { int jv_20e0c = opq_670e ^ 0xFE5D;
            jv_20e0c += (jv_20e0c >> 2) + 0x12;
          (void)jv_20e0c; }
    }
    h[0] = h[--hn];
    if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
        { int jv_bdb64 = opq_670e ^ 0x2DD5;
            jv_bdb64 ^= (jv_bdb64 << 3) | 0x5B57;
            jv_bdb64 = (jv_bdb64 * 0x3B) % 0x7FFFFFFF;
          (void)jv_bdb64; }
    }
    int i = 0;
    if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
        { int jv_1bc18 = opq_670e ^ 0xDEAF;
            jv_1bc18 ^= (jv_1bc18 << 3) | 0x5709;
            jv_1bc18 = (jv_1bc18 * 0x2E) % 0x7FFFFFFF;
            jv_1bc18 += (jv_1bc18 >> 2) + 0x2;
          (void)jv_1bc18; }
    }
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
            { int jv_1476a = opq_670e ^ 0x75E2;
                jv_1476a = (jv_1476a * 0x38) % 0x7FFFFFFF;
              (void)jv_1476a; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
            { int jv_5506a = opq_670e ^ 0xE17C;
                jv_5506a += (jv_5506a >> 2) + 0xC7;
                jv_5506a = (jv_5506a * 0xF) % 0x7FFFFFFF;
              (void)jv_5506a; }
        }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
        { int jv_fcdb2 = opq_670e ^ 0xA995;
            jv_fcdb2 += (jv_fcdb2 >> 2) + 0x66;
            jv_fcdb2 = (jv_fcdb2 * 0x1B) % 0x7FFFFFFF;
          (void)jv_fcdb2; }
    }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_670e * opq_670e) % 4) == 2)) {
        { int jv_2cc94 = opq_670e ^ 0xF115;
            jv_2cc94 = (jv_2cc94 * 0x1F) % 0x7FFFFFFF;
            jv_2cc94 += (jv_2cc94 >> 2) + 0x5D;
            jv_2cc94 ^= (jv_2cc94 << 3) | 0x6733;
          (void)jv_2cc94; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_670e * opq_670e + opq_670e_b * opq_670e_b) % 4) == 3)) {
        { int jv_a2098 = opq_670e ^ 0xB19A;
            jv_a2098 += (jv_a2098 >> 2) + 0x5;
            jv_a2098 ^= (jv_a2098 << 3) | 0x6ECD;
            jv_a2098 = (jv_a2098 * 0x34) % 0x7FFFFFFF;
          (void)jv_a2098; }
    }
    return 0;
}
