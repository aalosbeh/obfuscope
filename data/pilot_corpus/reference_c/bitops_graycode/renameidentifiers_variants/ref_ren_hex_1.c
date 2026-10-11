#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int v_d65d8b = 0, transitions = 0;
    unsigned v_cd4c38 = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) v_d65d8b++;
        unsigned d = g ^ v_cd4c38;
        while (d) { transitions += d & 1u; d >>= 1; }
        v_cd4c38 = g;
    }
    printf("%d %d\n", v_d65d8b, transitions);
    return 0;
}
