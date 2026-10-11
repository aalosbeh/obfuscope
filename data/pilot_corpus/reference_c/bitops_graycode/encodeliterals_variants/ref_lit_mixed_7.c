#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x8ED - 0x8EC)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x650C3EFB ^ 0x650C3EFA)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x6AD86FE6 ^ 0x6AD86FE6), transitions = (0x49EC05FA ^ 0x49EC05FA);
    unsigned prev = to_gray((0x47F - 0x47F));
    for (unsigned i = (0x9E - 0x9E); i < (0x70516F6D ^ 0x70516B6D); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x2CE03251u ^ 0x2CE03250u); d >>= (0xA81 - 0xA80); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x35D1FDA1 ^ 0x35D1FDA1);
}
