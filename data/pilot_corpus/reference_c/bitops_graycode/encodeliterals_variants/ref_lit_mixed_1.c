#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0xC9 - 0xC8)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x4A4 - 0x4A3)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x7AFFBA7 ^ 0x7AFFBA7), transitions = (0x69816F5C ^ 0x69816F5C);
    unsigned prev = to_gray((0x221B1574 ^ 0x221B1574));
    for (unsigned i = (0x640A43E0 ^ 0x640A43E0); i < (0xD98 - 0x998); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xF6Fu - 0xF6Eu); d >>= (0x3FD5680 ^ 0x3FD5681); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0xC9 - 0xC9);
}
