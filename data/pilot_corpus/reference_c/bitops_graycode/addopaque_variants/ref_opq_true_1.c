#include <stdio.h>
static volatile int opq_9782 = 7;
static volatile int opq_9782_b = 3;

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    if (((opq_9782 * opq_9782 - opq_9782) % 2 == 0)) { opq_9782_b ^= 0; }
    int roundtrip = 0, transitions = 0;
    if ((((opq_9782 * opq_9782 + opq_9782) % 2) == 0)) { opq_9782_b ^= 0; }
    unsigned prev = to_gray(0);
    if (((opq_9782 * opq_9782 - opq_9782) % 2 == 0)) { opq_9782_b ^= 0; }
    for (unsigned i = 0; i < 1024; i++) {
        if ((((opq_9782 * (opq_9782 + 1)) % 2) == 0)) { opq_9782_b ^= 0; }
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return 0;
}
