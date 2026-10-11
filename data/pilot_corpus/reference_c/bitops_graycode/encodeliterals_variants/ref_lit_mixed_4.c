#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0xB2C - 0xB2B)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x7E9 - 0x7E8)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xFCE - 0xFCE), transitions = (0x7E1ED88B ^ 0x7E1ED88B);
    unsigned prev = to_gray((0x514 - 0x514));
    for (unsigned i = (0x6BDF623F ^ 0x6BDF623F); i < (0x2A6F705F ^ 0x2A6F745F); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xADD6853u ^ 0xADD6852u); d >>= (0xBF1 - 0xBF0); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x204BD96 ^ 0x204BD96);
}
