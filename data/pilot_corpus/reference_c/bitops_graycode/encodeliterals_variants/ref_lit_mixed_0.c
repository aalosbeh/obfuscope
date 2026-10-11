#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0xC8E - 0xC8D)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0xCBA - 0xCB9)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xBA - 0xBA), transitions = (0x2C346A2 ^ 0x2C346A2);
    unsigned prev = to_gray((0x872079E ^ 0x872079E));
    for (unsigned i = (0x342 - 0x342); i < (0x51514907 ^ 0x51514D07); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x8E6u - 0x8E5u); d >>= (0xF88 - 0xF87); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x5C831B74 ^ 0x5C831B74);
}
