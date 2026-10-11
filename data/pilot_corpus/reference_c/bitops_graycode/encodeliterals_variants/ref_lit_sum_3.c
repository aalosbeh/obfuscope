#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x290 - 0x28F)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0xE81 - 0xE80)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x913 - 0x913), transitions = (0xE36 - 0xE36);
    unsigned prev = to_gray((0x574 - 0x574));
    for (unsigned i = (0xBFA - 0xBFA); i < (0xFAC - 0xBAC); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x430u - 0x42Fu); d >>= (0x989 - 0x988); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x563 - 0x563);
}
