#include <stdio.h>
static volatile int opq_8ff5 = 7;
static volatile int opq_8ff5_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    if ((((opq_8ff5 * opq_8ff5 + opq_8ff5_b * opq_8ff5_b) % 4) == 3)) {
        { int jv_aaaba = opq_8ff5 ^ 0x30D9;
            jv_aaaba += (jv_aaaba >> 2) + 0x83;
          (void)jv_aaaba; }
    }
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    if ((((opq_8ff5 * opq_8ff5 + opq_8ff5_b * opq_8ff5_b) % 4) == 3)) {
        { int jv_f4a8d = opq_8ff5 ^ 0x8019;
            jv_f4a8d += (jv_f4a8d >> 2) + 0x70;
          (void)jv_f4a8d; }
    }
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_8ff5 * opq_8ff5) % 4) == 2)) {
            { int jv_3f918 = opq_8ff5 ^ 0xB35;
                jv_3f918 = (jv_3f918 * 0x37) % 0x7FFFFFFF;
              (void)jv_3f918; }
        }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_8ff5 * opq_8ff5 + opq_8ff5_b * opq_8ff5_b) % 4) == 3)) {
        { int jv_45818 = opq_8ff5 ^ 0xEF28;
            jv_45818 ^= (jv_45818 << 3) | 0xBB61;
            jv_45818 += (jv_45818 >> 2) + 0x98;
          (void)jv_45818; }
    }
    return 0;
}
