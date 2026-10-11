#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x60D - 0x60C)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0xB1F - 0xB1E)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xEC - 0xEC), transitions = (0xBFC - 0xBFC);
    unsigned prev = to_gray((0x6CD - 0x6CD));
    for (unsigned i = (0xE6 - 0xE6); i < (0x1095 - 0xC95); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x4u - 0x3u); d >>= (0x98B - 0x98A); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x880 - 0x880);
}
