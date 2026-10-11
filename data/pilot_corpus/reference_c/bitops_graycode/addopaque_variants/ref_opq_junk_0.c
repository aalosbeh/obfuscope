#include <stdio.h>
static volatile int opq_a044 = 7;
static volatile int opq_a044_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    if ((((opq_a044 * opq_a044) % 4) == 2)) {
        { int jv_efa70 = opq_a044 ^ 0x2B33;
            jv_efa70 = (jv_efa70 * 0x16) % 0x7FFFFFFF;
          (void)jv_efa70; }
    }
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_a044 * opq_a044 + opq_a044_b * opq_a044_b) % 4) == 3)) {
            { int jv_c8395 = opq_a044 ^ 0x44A9;
                jv_c8395 = (jv_c8395 * 0x37) % 0x7FFFFFFF;
                jv_c8395 += (jv_c8395 >> 2) + 0x3C;
                jv_c8395 ^= (jv_c8395 << 3) | 0x9FFF;
              (void)jv_c8395; }
        }
        unsigned g = to_gray(i);
        if ((((opq_a044 * opq_a044) % 4) == 2)) {
            { int jv_db553 = opq_a044 ^ 0x72B6;
                jv_db553 = (jv_db553 * 0x38) % 0x7FFFFFFF;
              (void)jv_db553; }
        }
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_a044 * opq_a044) % 4) == 2)) {
            { int jv_6b4b4 = opq_a044 ^ 0x52D2;
                jv_6b4b4 ^= (jv_6b4b4 << 3) | 0xF403;
                jv_6b4b4 += (jv_6b4b4 >> 2) + 0x5F;
              (void)jv_6b4b4; }
        }
    }
    printf("%d %d\n", roundtrip, transitions);
    return 0;
}
