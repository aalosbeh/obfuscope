#include <stdio.h>
static volatile int opq_776e = 7;
static volatile int opq_776e_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if ((((opq_776e * (opq_776e + 1)) % 2) == 0)) { opq_776e_b ^= 0; }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if (((opq_776e * opq_776e - opq_776e) % 2 == 0)) { opq_776e_b ^= 0; }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_776e * opq_776e + opq_776e_b * opq_776e_b) % 4) == 3)) {
            { int jv_fd54e = opq_776e ^ 0x4B5C;
                jv_fd54e += (jv_fd54e >> 2) + 0x76;
                jv_fd54e ^= (jv_fd54e << 3) | 0x4657;
              (void)jv_fd54e; }
        }
    }
}
static int pop(void) {
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    if ((((opq_776e * (opq_776e + 1)) % 2) == 0)) { opq_776e_b ^= 0; }
    for (;;) {
        if ((((opq_776e * opq_776e + opq_776e_b * opq_776e_b) % 4) == 3)) {
            { int jv_10ab0 = opq_776e ^ 0x4FBF;
                jv_10ab0 ^= (jv_10ab0 << 3) | 0x4968;
                jv_10ab0 += (jv_10ab0 >> 2) + 0x5D;
                jv_10ab0 = (jv_10ab0 * 0x27) % 0x7FFFFFFF;
              (void)jv_10ab0; }
        }
        int l = 2 * i + 1, r = l + 1, m = i;
        if ((((opq_776e * opq_776e + opq_776e) % 2) == 0)) { opq_776e_b ^= 0; }
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_776e * opq_776e) % 4) == 2)) {
            { int jv_1aa92 = opq_776e ^ 0xBF5F;
                jv_1aa92 = (jv_1aa92 * 0x28) % 0x7FFFFFFF;
                jv_1aa92 ^= (jv_1aa92 << 3) | 0x22E;
                jv_1aa92 += (jv_1aa92 >> 2) + 0x7B;
              (void)jv_1aa92; }
        }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_776e * opq_776e) % 4) == 2)) {
        { int jv_8ddea = opq_776e ^ 0x52D4;
            jv_8ddea ^= (jv_8ddea << 3) | 0xC9E2;
            jv_8ddea = (jv_8ddea * 0x3) % 0x7FFFFFFF;
            jv_8ddea += (jv_8ddea >> 2) + 0xC3;
          (void)jv_8ddea; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_776e * opq_776e) % 4) == 2)) {
        { int jv_9eddb = opq_776e ^ 0x6FE2;
            jv_9eddb = (jv_9eddb * 0x4) % 0x7FFFFFFF;
            jv_9eddb += (jv_9eddb >> 2) + 0xAB;
            jv_9eddb ^= (jv_9eddb << 3) | 0x3ABD;
          (void)jv_9eddb; }
    }
    return 0;
}
