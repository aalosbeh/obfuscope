#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x5EE - 0x5ED)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x7BD - 0x7BC)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xBCE - 0xBCE), transitions = (0x19F - 0x19F);
    unsigned prev = to_gray((0x4E4 - 0x4E4));
    for (unsigned i = (0xFB0 - 0xFB0); i < (0x49F - 0x9F); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x798u - 0x797u); d >>= (0x301 - 0x300); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x640 - 0x640);
}
