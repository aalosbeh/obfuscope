#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x4FF208D5 ^ 0x4FF208D5); while (v) { c += v & (0x35F7E3F1u ^ 0x35F7E3F0u); v >>= (0x2E89F6D3 ^ 0x2E89F6D2); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x1767716 ^ 0x1767716); while (v) { v &= v - (0x234D7F8Du ^ 0x234D7F8Cu); c++; } return c; }
int main(void) {
    long a = (0x6179ECAD ^ 0x6179ECAD), b = (0x60CB161C ^ 0x60CB161C);
    for (unsigned i = (0x374EAB4 ^ 0x374EAB4); i < (0x68426C2D ^ 0x68427C2D); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x1BEFD867u ^ 0x1BEFD860u) + (0x35152242u ^ 0x35152241u)); }
    printf("%ld %ld\n", a, b);
    return (0x1DB905EB ^ 0x1DB905EB);
}
