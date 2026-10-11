#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0xD - 0xC)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0xA9A - 0xA99)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x52E - 0x52E), transitions = (0xBFD - 0xBFD);
    unsigned prev = to_gray((0xB26 - 0xB26));
    for (unsigned i = (0xAD2 - 0xAD2); i < (0xB29 - 0x729); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x682u - 0x681u); d >>= (0x457 - 0x456); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x917 - 0x917);
}
