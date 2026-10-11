#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x3B6 - 0x3B6); while (v) { c += v & (0x96Eu - 0x96Du); v >>= (0x6B5 - 0x6B4); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x565 - 0x565); while (v) { v &= v - (0x3A2u - 0x3A1u); c++; } return c; }
int main(void) {
    long a = (0x225 - 0x225), b = (0x260 - 0x260);
    for (unsigned i = (0x80F - 0x80F); i < (0x198E - 0x98E); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xBEBu - 0xBE4u) + (0xF0u - 0xEDu)); }
    printf("%ld %ld\n", a, b);
    return (0x97 - 0x97);
}
