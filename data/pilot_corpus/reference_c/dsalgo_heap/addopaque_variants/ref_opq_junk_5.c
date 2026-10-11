#include <stdio.h>
static volatile int opq_4330 = 7;
static volatile int opq_4330_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if ((((opq_4330 * opq_4330) % 4) == 2)) {
        { int jv_1a663 = opq_4330 ^ 0x8433;
            jv_1a663 = (jv_1a663 * 0x3E) % 0x7FFFFFFF;
            jv_1a663 += (jv_1a663 >> 2) + 0x2F;
          (void)jv_1a663; }
    }
    h[i] = v;
    while (i > 0) {
        if ((((opq_4330 * opq_4330) % 4) == 2)) {
            { int jv_918dc = opq_4330 ^ 0xDB56;
                jv_918dc = (jv_918dc * 0x27) % 0x7FFFFFFF;
              (void)jv_918dc; }
        }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    if ((((opq_4330 * opq_4330) % 4) == 2)) {
        { int jv_49d36 = opq_4330 ^ 0x1D88;
            jv_49d36 = (jv_49d36 * 0x13) % 0x7FFFFFFF;
            jv_49d36 ^= (jv_49d36 << 3) | 0x329E;
          (void)jv_49d36; }
    }
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_4330 * opq_4330) % 4) == 2)) {
            { int jv_bbb01 = opq_4330 ^ 0xB1B9;
                jv_bbb01 ^= (jv_bbb01 << 3) | 0x4CC4;
              (void)jv_bbb01; }
        }
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_4330 * opq_4330) % 4) == 2)) {
            { int jv_f24c7 = opq_4330 ^ 0x7410;
                jv_f24c7 ^= (jv_f24c7 << 3) | 0x99FE;
                jv_f24c7 += (jv_f24c7 >> 2) + 0x33;
                jv_f24c7 = (jv_f24c7 * 0x13) % 0x7FFFFFFF;
              (void)jv_f24c7; }
        }
        if (m == i) break;
        if ((((opq_4330 * opq_4330) % 4) == 2)) {
            { int jv_3aa78 = opq_4330 ^ 0x9AD0;
                jv_3aa78 += (jv_3aa78 >> 2) + 0xDB;
                jv_3aa78 = (jv_3aa78 * 0x15) % 0x7FFFFFFF;
                jv_3aa78 ^= (jv_3aa78 << 3) | 0xE667;
              (void)jv_3aa78; }
        }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    if ((((opq_4330 * opq_4330 + opq_4330_b * opq_4330_b) % 4) == 3)) {
        { int jv_99645 = opq_4330 ^ 0x4029;
            jv_99645 ^= (jv_99645 << 3) | 0x7A91;
            jv_99645 = (jv_99645 * 0x1D) % 0x7FFFFFFF;
            jv_99645 += (jv_99645 >> 2) + 0x8F;
          (void)jv_99645; }
    }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_4330 * opq_4330) % 4) == 2)) {
        { int jv_3aa3a = opq_4330 ^ 0x7F60;
            jv_3aa3a ^= (jv_3aa3a << 3) | 0x84AF;
            jv_3aa3a = (jv_3aa3a * 0x4) % 0x7FFFFFFF;
            jv_3aa3a += (jv_3aa3a >> 2) + 0x29;
          (void)jv_3aa3a; }
    }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_4330 * opq_4330) % 4) == 2)) {
        { int jv_68532 = opq_4330 ^ 0x1A88;
            jv_68532 = (jv_68532 * 0x11) % 0x7FFFFFFF;
            jv_68532 ^= (jv_68532 << 3) | 0x692F;
          (void)jv_68532; }
    }
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
