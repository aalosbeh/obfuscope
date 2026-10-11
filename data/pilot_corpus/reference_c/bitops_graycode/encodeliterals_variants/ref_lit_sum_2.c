#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x206 - 0x205)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x848 - 0x847)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xB23 - 0xB23), transitions = (0x3FF - 0x3FF);
    unsigned prev = to_gray((0x455 - 0x455));
    for (unsigned i = (0xFB7 - 0xFB7); i < (0x10DF - 0xCDF); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x4u - 0x3u); d >>= (0x947 - 0x946); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x5AA - 0x5AA);
}
