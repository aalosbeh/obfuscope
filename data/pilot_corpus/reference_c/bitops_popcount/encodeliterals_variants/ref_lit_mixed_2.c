#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x5F8 - 0x5F8); while (v) { c += v & (0x50C3B8C3u ^ 0x50C3B8C2u); v >>= (0x6F0C0DF5 ^ 0x6F0C0DF4); } return c; }
static int pc_kernighan(unsigned v) { int c = (0xFF1 - 0xFF1); while (v) { v &= v - (0x5E73C740u ^ 0x5E73C741u); c++; } return c; }
int main(void) {
    long a = (0x4FF - 0x4FF), b = (0x24295F49 ^ 0x24295F49);
    for (unsigned i = (0x75BFB7F3 ^ 0x75BFB7F3); i < (0x15C5 - 0x5C5); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xA43u - 0xA3Cu) + (0x686u - 0x683u)); }
    printf("%ld %ld\n", a, b);
    return (0x65D4BCB5 ^ 0x65D4BCB5);
}
