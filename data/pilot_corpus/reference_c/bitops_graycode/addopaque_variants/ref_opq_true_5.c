#include <stdio.h>
static volatile int opq_4281 = 7;
static volatile int opq_4281_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    if ((((opq_4281 * opq_4281 + opq_4281) % 2) == 0)) { opq_4281_b ^= 0; }
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        if ((((opq_4281 * opq_4281 + opq_4281) % 2) == 0)) { opq_4281_b ^= 0; }
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
        if ((((opq_4281 * opq_4281 + opq_4281) % 2) == 0)) { opq_4281_b ^= 0; }
    }
    printf("%d %d\n", roundtrip, transitions);
    if ((((opq_4281 * (opq_4281 + 1)) % 2) == 0)) { opq_4281_b ^= 0; }
    return 0;
}
