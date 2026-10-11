#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x59CBFF2A ^ 0x59CBFF2A); while (v) { c += v & (0x54AA028Eu ^ 0x54AA028Fu); v >>= (0x471025BE ^ 0x471025BF); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x2AB5827E ^ 0x2AB5827E); while (v) { v &= v - (0x76B636E0u ^ 0x76B636E1u); c++; } return c; }
int main(void) {
    long a = (0x5CDA88BA ^ 0x5CDA88BA), b = (0x2D412FA0 ^ 0x2D412FA0);
    for (unsigned i = (0x3FE98B0F ^ 0x3FE98B0F); i < (0x51E92522 ^ 0x51E93522); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x7CCB9CF2u ^ 0x7CCB9CF5u) + (0x71A916E0u ^ 0x71A916E3u)); }
    printf("%ld %ld\n", a, b);
    return (0x42A4D485 ^ 0x42A4D485);
}
