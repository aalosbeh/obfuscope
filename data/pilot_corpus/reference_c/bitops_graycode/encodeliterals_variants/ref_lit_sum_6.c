#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x7C3 - 0x7C2)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x5E5 - 0x5E4)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0xBAF - 0xBAF), transitions = (0x870 - 0x870);
    unsigned prev = to_gray((0xCE4 - 0xCE4));
    for (unsigned i = (0x9FB - 0x9FB); i < (0x58C - 0x18C); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xB85u - 0xB84u); d >>= (0x292 - 0x291); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0xB5C - 0xB5C);
}
