#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x74C - 0x74C); while (v) { c += v & (0xEF7u - 0xEF6u); v >>= (0x342 - 0x341); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x4D1 - 0x4D1); while (v) { v &= v - (0x4F3u - 0x4F2u); c++; } return c; }
int main(void) {
    long a = (0x114 - 0x114), b = (0xEFD - 0xEFD);
    for (unsigned i = (0x354 - 0x354); i < (0x1243 - 0x243); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x283u - 0x27Cu) + (0x8C5u - 0x8C2u)); }
    printf("%ld %ld\n", a, b);
    return (0x905 - 0x905);
}
