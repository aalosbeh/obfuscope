#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x7892A42D ^ 0x7892A42C)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x5E7BA783 ^ 0x5E7BA782)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x21CA4DAD ^ 0x21CA4DAD), transitions = (0x797B54AA ^ 0x797B54AA);
    unsigned prev = to_gray((0x4C40D2A1 ^ 0x4C40D2A1));
    for (unsigned i = (0x19657E1C ^ 0x19657E1C); i < (0x3EDE91CE ^ 0x3EDE95CE); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x507CF3C7u ^ 0x507CF3C6u); d >>= (0x24B6D7 ^ 0x24B6D6); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0xB090BC9 ^ 0xB090BC9);
}
