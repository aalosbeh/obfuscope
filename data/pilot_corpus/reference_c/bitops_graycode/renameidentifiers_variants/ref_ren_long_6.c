#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int lpueonhvtucfgdemmfm = 0, transitions = 0;
    unsigned iaeihusqoowrtrcumyjsv = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) lpueonhvtucfgdemmfm++;
        unsigned d = g ^ iaeihusqoowrtrcumyjsv;
        while (d) { transitions += d & 1u; d >>= 1; }
        iaeihusqoowrtrcumyjsv = g;
    }
    printf("%d %d\n", lpueonhvtucfgdemmfm, transitions);
    return 0;
}
