#include <stdio.h>
static volatile int opq_6677 = 7;
static volatile int opq_6677_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    if ((((opq_6677 * opq_6677) % 4) == 2)) {
        { int jv_7d03a = opq_6677 ^ 0x141F;
            jv_7d03a = (jv_7d03a * 0x19) % 0x7FFFFFFF;
          (void)jv_7d03a; }
    }
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_6677 * opq_6677) % 4) == 2)) {
            { int jv_3d018 = opq_6677 ^ 0x8E41;
                jv_3d018 ^= (jv_3d018 << 3) | 0xE080;
                jv_3d018 = (jv_3d018 * 0x25) % 0x7FFFFFFF;
                jv_3d018 += (jv_3d018 >> 2) + 0x53;
              (void)jv_3d018; }
        }
        unsigned g = to_gray(i);
        if ((((opq_6677 * opq_6677) % 4) == 2)) {
            { int jv_fcd61 = opq_6677 ^ 0xAF8D;
                jv_fcd61 = (jv_fcd61 * 0x3E) % 0x7FFFFFFF;
                jv_fcd61 += (jv_fcd61 >> 2) + 0x69;
              (void)jv_fcd61; }
        }
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_6677 * opq_6677) % 4) == 2)) {
            { int jv_291d0 = opq_6677 ^ 0x596E;
                jv_291d0 ^= (jv_291d0 << 3) | 0xC00F;
              (void)jv_291d0; }
        }
    }
    printf("%d %d\n", roundtrip, transitions);
    return 0;
}
