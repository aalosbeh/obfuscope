#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x40F760A7 ^ 0x40F760A6)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x68743405 ^ 0x68743404)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x61C28C46 ^ 0x61C28C46), transitions = (0x2BC03C2 ^ 0x2BC03C2);
    unsigned prev = to_gray((0x6F82C623 ^ 0x6F82C623));
    for (unsigned i = (0x4B92EF4C ^ 0x4B92EF4C); i < (0x44019349 ^ 0x44019749); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x41BE81F1u ^ 0x41BE81F0u); d >>= (0x7999F8A8 ^ 0x7999F8A9); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x54CAB16A ^ 0x54CAB16A);
}
