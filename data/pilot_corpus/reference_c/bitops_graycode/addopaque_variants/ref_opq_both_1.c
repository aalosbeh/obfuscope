#include <stdio.h>
static volatile int opq_2c90 = 7;
static volatile int opq_2c90_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    if (((opq_2c90 * opq_2c90 - opq_2c90) % 2 == 0)) { opq_2c90_b ^= 0; }
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        if (((opq_2c90 * opq_2c90 - opq_2c90) % 2 == 0)) { opq_2c90_b ^= 0; }
        unsigned g = to_gray(i);
        if ((((opq_2c90 * opq_2c90 + opq_2c90) % 2) == 0)) { opq_2c90_b ^= 0; }
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_2c90 * opq_2c90 + opq_2c90) % 2) == 0)) { opq_2c90_b ^= 0; }
    }
    printf("%d %d\n", roundtrip, transitions);
    return 0;
}
