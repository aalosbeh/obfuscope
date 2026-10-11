#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> (0x366754E6 ^ 0x366754E7)); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= (0x2D300AB7 ^ 0x2D300AB6)) n ^= g; return n; }
int main(void) {
    int roundtrip = (0x305A64BB ^ 0x305A64BB), transitions = (0x7F9B8A79 ^ 0x7F9B8A79);
    unsigned prev = to_gray((0x37C3E456 ^ 0x37C3E456));
    for (unsigned i = (0x7FF90DF5 ^ 0x7FF90DF5); i < (0x5A2F628E ^ 0x5A2F668E); i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & (0x288D077Bu ^ 0x288D077Au); d >>= (0x77005A0E ^ 0x77005A0F); }
        prev = g;
    }
    printf("%d %d\n", roundtrip, transitions);
    return (0x68926924 ^ 0x68926924);
}
