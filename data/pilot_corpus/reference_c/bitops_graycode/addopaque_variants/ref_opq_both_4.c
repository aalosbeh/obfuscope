#include <stdio.h>
static volatile int opq_1f17 = 7;
static volatile int opq_1f17_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    if ((((opq_1f17 * (opq_1f17 + 1)) % 2) == 0)) { opq_1f17_b ^= 0; }
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_1f17 * opq_1f17) % 4) == 2)) {
            { int jv_f3bb3 = opq_1f17 ^ 0xCC8E;
                jv_f3bb3 = (jv_f3bb3 * 0x2F) % 0x7FFFFFFF;
                jv_f3bb3 ^= (jv_f3bb3 << 3) | 0x24A2;
              (void)jv_f3bb3; }
        }
        unsigned g = to_gray(i);
        if ((((opq_1f17 * opq_1f17) % 4) == 2)) {
            { int jv_21789 = opq_1f17 ^ 0x1DF3;
                jv_21789 += (jv_21789 >> 2) + 0xEA;
              (void)jv_21789; }
        }
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_1f17 * opq_1f17 + opq_1f17) % 2) == 0)) { opq_1f17_b ^= 0; }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return 0;
}
