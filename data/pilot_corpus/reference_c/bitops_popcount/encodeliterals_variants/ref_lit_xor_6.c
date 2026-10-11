#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x1F542E6F ^ 0x1F542E6F); while (v) { c += v & (0x1689F41u ^ 0x1689F40u); v >>= (0x39AE4B1F ^ 0x39AE4B1E); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x56062280 ^ 0x56062280); while (v) { v &= v - (0x3B2C694u ^ 0x3B2C695u); c++; } return c; }
int main(void) {
    long a = (0x1A30AC2 ^ 0x1A30AC2), b = (0x195CC134 ^ 0x195CC134);
    for (unsigned i = (0x5A41F3AF ^ 0x5A41F3AF); i < (0x19425519 ^ 0x19424519); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xA38FBACu ^ 0xA38FBABu) + (0x61C0565u ^ 0x61C0566u)); }
    printf("%ld %ld\n", a, b);
    return (0x3CBBABE8 ^ 0x3CBBABE8);
}
