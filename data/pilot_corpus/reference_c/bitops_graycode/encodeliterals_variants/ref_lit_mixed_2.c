#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x4CE57BC4 ^ 0x4CE57BC5)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x435D4325 ^ 0x435D4324)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x75F2AFA9 ^ 0x75F2AFA9), transitions = (0x31A71F04 ^ 0x31A71F04);
    unsigned prev = to_gray((0xFBA - 0xFBA));
    for (unsigned i = (0xFA0 - 0xFA0); i < (0x4BA - 0xBA); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xB0Au - 0xB09u); d >>= (0x3B63ED6 ^ 0x3B63ED7); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0xA2C - 0xA2C);
}
