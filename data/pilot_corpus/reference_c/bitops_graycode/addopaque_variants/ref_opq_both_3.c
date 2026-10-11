#include <stdio.h>
static volatile int opq_628d = 7;
static volatile int opq_628d_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        if (((opq_628d * opq_628d - opq_628d) % 2 == 0)) { opq_628d_b ^= 0; }
        unsigned g = to_gray(i);
        if ((((opq_628d * opq_628d + opq_628d) % 2) == 0)) { opq_628d_b ^= 0; }
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_628d * opq_628d + opq_628d_b * opq_628d_b) % 4) == 3)) {
            { int jv_e06f4 = opq_628d ^ 0x16E9;
                jv_e06f4 ^= (jv_e06f4 << 3) | 0xA6A4;
              (void)jv_e06f4; }
        }
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_628d * (opq_628d + 1)) % 2) == 0)) { opq_628d_b ^= 0; }
    return 0;
}
