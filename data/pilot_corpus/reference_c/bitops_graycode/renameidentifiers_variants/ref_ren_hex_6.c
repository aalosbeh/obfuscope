#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int v_250f09 = 0, transitions = 0;
    unsigned v_39eb7d = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) v_250f09++;
        unsigned d = g ^ v_39eb7d;
        while (d) { transitions += d & 1u; d >>= 1; }
        v_39eb7d = g;
    }
    printf("%d %d\n", v_250f09, transitions);
    return 0;
}
