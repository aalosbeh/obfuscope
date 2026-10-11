#include <stdio.h>
static volatile int opq_495a = 7;
static volatile int opq_495a_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    if ((((opq_495a * opq_495a + opq_495a_b * opq_495a_b) % 4) == 3)) {
        { int jv_bf460 = opq_495a ^ 0x12B4;
            jv_bf460 = (jv_bf460 * 0x11) % 0x7FFFFFFF;
            jv_bf460 += (jv_bf460 >> 2) + 0x98;
            jv_bf460 ^= (jv_bf460 << 3) | 0x69DA;
          (void)jv_bf460; }
    }
    unsigned prev = to_gray(0);
    if ((((opq_495a * opq_495a) % 4) == 2)) {
        { int jv_72dfc = opq_495a ^ 0x8F77;
            jv_72dfc += (jv_72dfc >> 2) + 0x93;
          (void)jv_72dfc; }
    }
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if ((((opq_495a * opq_495a + opq_495a_b * opq_495a_b) % 4) == 3)) {
            { int jv_32de5 = opq_495a ^ 0x9CF1;
                jv_32de5 ^= (jv_32de5 << 3) | 0xE27B;
                jv_32de5 += (jv_32de5 >> 2) + 0x84;
                jv_32de5 = (jv_32de5 * 0x1C) % 0x7FFFFFFF;
              (void)jv_32de5; }
        }
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_495a * opq_495a + opq_495a_b * opq_495a_b) % 4) == 3)) {
        { int jv_74797 = opq_495a ^ 0x13DF;
            jv_74797 += (jv_74797 >> 2) + 0xA4;
            jv_74797 = (jv_74797 * 0xE) % 0x7FFFFFFF;
          (void)jv_74797; }
    }
    return 0;
}
