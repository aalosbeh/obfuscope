#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x205 - 0x205); while (v) { c += v & (0xDCEu - 0xDCDu); v >>= (0x120 - 0x11F); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x974 - 0x974); while (v) { v &= v - (0x26Au - 0x269u); c++; } return c; }
int main(void) {
    long a = (0x158 - 0x158), b = (0x94A - 0x94A);
    for (unsigned i = (0xE0A - 0xE0A); i < (0x1BEF - 0xBEF); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x603u - 0x5FCu) + (0x813u - 0x810u)); }
    printf("%ld %ld\n", a, b);
    return (0x4AF - 0x4AF);
}
