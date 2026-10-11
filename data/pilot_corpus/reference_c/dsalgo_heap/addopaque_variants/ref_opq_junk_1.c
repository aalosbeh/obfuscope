#include <stdio.h>
static volatile int opq_f619 = 7;
static volatile int opq_f619_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    if ((((opq_f619 * opq_f619) % 4) == 2)) {
        { int jv_c4333 = opq_f619 ^ 0x6F80;
            jv_c4333 = (jv_c4333 * 0x2C) % 0x7FFFFFFF;
            jv_c4333 ^= (jv_c4333 << 3) | 0x477E;
          (void)jv_c4333; }
    }
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_f619 * opq_f619 + opq_f619_b * opq_f619_b) % 4) == 3)) {
            { int jv_29511 = opq_f619 ^ 0xEC5C;
                jv_29511 += (jv_29511 >> 2) + 0xA6;
              (void)jv_29511; }
        }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_f619 * opq_f619) % 4) == 2)) {
        { int jv_41ec8 = opq_f619 ^ 0x8C16;
            jv_41ec8 += (jv_41ec8 >> 2) + 0x3F;
            jv_41ec8 = (jv_41ec8 * 0x2F) % 0x7FFFFFFF;
            jv_41ec8 ^= (jv_41ec8 << 3) | 0x4F26;
          (void)jv_41ec8; }
    }
    h[0] = h[--hn];
    if ((((opq_f619 * opq_f619) % 4) == 2)) {
        { int jv_37e4a = opq_f619 ^ 0x5651;
            jv_37e4a ^= (jv_37e4a << 3) | 0xD202;
            jv_37e4a = (jv_37e4a * 0x7) % 0x7FFFFFFF;
            jv_37e4a += (jv_37e4a >> 2) + 0x95;
          (void)jv_37e4a; }
    }
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_f619 * opq_f619 + opq_f619_b * opq_f619_b) % 4) == 3)) {
            { int jv_29378 = opq_f619 ^ 0x8B7;
                jv_29378 ^= (jv_29378 << 3) | 0x10A8;
              (void)jv_29378; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        if ((((opq_f619 * opq_f619) % 4) == 2)) {
            { int jv_83054 = opq_f619 ^ 0x5FC4;
                jv_83054 = (jv_83054 * 0x28) % 0x7FFFFFFF;
                jv_83054 ^= (jv_83054 << 3) | 0xF086;
              (void)jv_83054; }
        }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
        if ((((opq_f619 * opq_f619) % 4) == 2)) {
            { int jv_9731c = opq_f619 ^ 0x3FB3;
                jv_9731c += (jv_9731c >> 2) + 0x13;
              (void)jv_9731c; }
        }
    }
    return top;
}
int main(void) {
    if ((((opq_f619 * opq_f619) % 4) == 2)) {
        { int jv_ddbc9 = opq_f619 ^ 0xD5B8;
            jv_ddbc9 += (jv_ddbc9 >> 2) + 0x44;
            jv_ddbc9 = (jv_ddbc9 * 0x2F) % 0x7FFFFFFF;
            jv_ddbc9 ^= (jv_ddbc9 << 3) | 0xD010;
          (void)jv_ddbc9; }
    }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_f619 * opq_f619 + opq_f619_b * opq_f619_b) % 4) == 3)) {
        { int jv_17657 = opq_f619 ^ 0xA96F;
            jv_17657 ^= (jv_17657 << 3) | 0x3DE8;
          (void)jv_17657; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
