#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x3AFF483 ^ 0x3AFF482)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x2EAA7F6E ^ 0x2EAA7F6F)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x346295A ^ 0x346295A), transitions = (0x6CD9040F ^ 0x6CD9040F);
    unsigned prev = to_gray((0x1BEB7B28 ^ 0x1BEB7B28));
    for (unsigned i = (0x6446B777 ^ 0x6446B777); i < (0x3EE1A6F6 ^ 0x3EE1A2F6); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0xFAB04D1u ^ 0xFAB04D0u); d >>= (0x76C11D6 ^ 0x76C11D7); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x4F60D34B ^ 0x4F60D34B);
}
