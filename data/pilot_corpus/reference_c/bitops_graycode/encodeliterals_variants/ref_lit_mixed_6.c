#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x4CF2B0FB ^ 0x4CF2B0FA)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x18530542 ^ 0x18530543)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xC983D1A ^ 0xC983D1A), transitions = (0xE1B - 0xE1B);
    unsigned prev = to_gray((0x3CA - 0x3CA));
    for (unsigned i = (0x413D77AB ^ 0x413D77AB); i < (0x2EA872EF ^ 0x2EA876EF); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xA1Fu - 0xA1Eu); d >>= (0x8B0 - 0x8AF); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x2DB7EC44 ^ 0x2DB7EC44);
}
