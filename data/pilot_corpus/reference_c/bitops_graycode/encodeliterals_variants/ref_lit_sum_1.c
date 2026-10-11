#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x3E - 0x3D)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0xC12 - 0xC11)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x924 - 0x924), transitions = (0x790 - 0x790);
    unsigned prev = to_gray((0xA01 - 0xA01));
    for (unsigned i = (0x314 - 0x314); i < (0x575 - 0x175); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x7C2u - 0x7C1u); d >>= (0xF73 - 0xF72); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x1F0 - 0x1F0);
}
