#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x6B48E1EE ^ 0x6B48E1EF)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x2C974441 ^ 0x2C974440)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x76D5EE1F ^ 0x76D5EE1F), transitions = (0xC91536E ^ 0xC91536E);
    unsigned prev = to_gray((0x3EBADE10 ^ 0x3EBADE10));
    for (unsigned i = (0x52A8DBF ^ 0x52A8DBF); i < (0x40A9B3CD ^ 0x40A9B7CD); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x432FEA99u ^ 0x432FEA98u); d >>= (0x4895C840 ^ 0x4895C841); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x44D711D5 ^ 0x44D711D5);
}
