#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x20FB6A8C ^ 0x20FB6A8D)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0xEA5 - 0xEA4)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x51F - 0x51F), transitions = (0xDAA - 0xDAA);
    unsigned prev = to_gray((0xF0B - 0xF0B));
    for (unsigned i = (0x11CD12C4 ^ 0x11CD12C4); i < (0x1078 - 0xC78); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x5FD54553u ^ 0x5FD54552u); d >>= (0xF206EC9 ^ 0xF206EC8); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x669A15B9 ^ 0x669A15B9);
}
