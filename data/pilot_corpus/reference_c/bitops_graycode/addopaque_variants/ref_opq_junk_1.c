#include <stdio.h>
static volatile int opq_e0be = 7;
static volatile int opq_e0be_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    if ((((opq_e0be * opq_e0be + opq_e0be_b * opq_e0be_b) % 4) == 3)) {
        { int jv_c3409 = opq_e0be ^ 0x8BE2;
            jv_c3409 ^= (jv_c3409 << 3) | 0x34FC;
            jv_c3409 += (jv_c3409 >> 2) + 0x6E;
          (void)jv_c3409; }
    }
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_e0be * opq_e0be) % 4) == 2)) {
            { int jv_47411 = opq_e0be ^ 0x2EC8;
                jv_47411 += (jv_47411 >> 2) + 0xE2;
                jv_47411 = (jv_47411 * 0x2D) % 0x7FFFFFFF;
                jv_47411 ^= (jv_47411 << 3) | 0xDAEB;
              (void)jv_47411; }
        }
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_e0be * opq_e0be + opq_e0be_b * opq_e0be_b) % 4) == 3)) {
            { int jv_ac245 = opq_e0be ^ 0x53B7;
                jv_ac245 ^= (jv_ac245 << 3) | 0x8685;
                jv_ac245 = (jv_ac245 * 0x10) % 0x7FFFFFFF;
                jv_ac245 += (jv_ac245 >> 2) + 0xFC;
              (void)jv_ac245; }
        }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_e0be * opq_e0be) % 4) == 2)) {
        { int jv_c6192 = opq_e0be ^ 0x1492;
            jv_c6192 = (jv_c6192 * 0xC) % 0x7FFFFFFF;
          (void)jv_c6192; }
    }
    return 0;
}
