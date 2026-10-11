#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int v_ff0ffa = 0, transitions = 0;
    unsigned v_8b6d6a = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) v_ff0ffa++;
        unsigned d = g ^ v_8b6d6a;
        while (d) { transitions += d & 1u; d >>= 1; }
        v_8b6d6a = g;
    }
    printf("%d %d\n", v_ff0ffa, transitions);
    return 0;
}
