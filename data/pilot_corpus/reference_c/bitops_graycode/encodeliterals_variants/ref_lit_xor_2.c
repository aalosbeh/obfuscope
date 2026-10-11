#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x43E96CC6 ^ 0x43E96CC7)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x33CC3B51 ^ 0x33CC3B50)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x6D92733D ^ 0x6D92733D), transitions = (0x1BC99A73 ^ 0x1BC99A73);
    unsigned prev = to_gray((0x1DC78FFB ^ 0x1DC78FFB));
    for (unsigned i = (0x38D26FB0 ^ 0x38D26FB0); i < (0x77A218F6 ^ 0x77A21CF6); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xE05F55Au ^ 0xE05F55Bu); d >>= (0x4E392F5E ^ 0x4E392F5F); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0xBB425BC ^ 0xBB425BC);
}
