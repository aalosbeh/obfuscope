#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x279 - 0x278)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x350 - 0x34F)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x280CFAA6 ^ 0x280CFAA6), transitions = (0x949 - 0x949);
    unsigned prev = to_gray((0x60D6B2ED ^ 0x60D6B2ED));
    for (unsigned i = (0x46136C0D ^ 0x46136C0D); i < (0x1EDCD790 ^ 0x1EDCD390); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xAD3u - 0xAD2u); d >>= (0x54 - 0x53); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x61D - 0x61D);
}
