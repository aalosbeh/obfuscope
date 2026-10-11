#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x5440625A ^ 0x5440625B)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x1A916673 ^ 0x1A916672)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x277EDD32 ^ 0x277EDD32), transitions = (0x43119AB0 ^ 0x43119AB0);
    unsigned prev = to_gray((0x11ED9F0 ^ 0x11ED9F0));
    for (unsigned i = (0x6EFEA43D ^ 0x6EFEA43D); i < (0x45139E38 ^ 0x45139A38); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x4242EFDFu ^ 0x4242EFDEu); d >>= (0x8EB89AB ^ 0x8EB89AA); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x12F42F2B ^ 0x12F42F2B);
}
