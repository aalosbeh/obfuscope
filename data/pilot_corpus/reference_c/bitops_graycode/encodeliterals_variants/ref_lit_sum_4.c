#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x8D2 - 0x8D1)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x6F9 - 0x6F8)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xD3F - 0xD3F), transitions = (0xDF4 - 0xDF4);
    unsigned prev = to_gray((0x173 - 0x173));
    for (unsigned i = (0xF40 - 0xF40); i < (0x1172 - 0xD72); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xA18u - 0xA17u); d >>= (0xF69 - 0xF68); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x952 - 0x952);
}
