#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x2D4B17D ^ 0x2D4B17C)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x384E232 ^ 0x384E233)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x325C1FE6 ^ 0x325C1FE6), transitions = (0x783D0484 ^ 0x783D0484);
    unsigned prev = to_gray((0x1B237928 ^ 0x1B237928));
    for (unsigned i = (0x5D95C66B ^ 0x5D95C66B); i < (0x14097E15 ^ 0x14097A15); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x1407298Cu ^ 0x1407298Du); d >>= (0x18E38F3A ^ 0x18E38F3B); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x3BD72812 ^ 0x3BD72812);
}
