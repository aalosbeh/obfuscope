#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int v_525cd7 = 0, transitions = 0;
    unsigned v_2bada6 = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) v_525cd7++;
        unsigned d = g ^ v_2bada6;
        while (d) { transitions += d & 1u; d >>= 1; }
        v_2bada6 = g;
    }
    printf("%d %d\n", v_525cd7, transitions);
    return 0;
}
