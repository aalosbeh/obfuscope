#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x227 - 0x227); while (v) { c += v & (0x9BFu - 0x9BEu); v >>= (0x170 - 0x16F); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x2BF - 0x2BF); while (v) { v &= v - (0x802u - 0x801u); c++; } return c; }
int main(void) {
    long a = (0xB8E - 0xB8E), b = (0xF8C - 0xF8C);
    for (unsigned i = (0x217 - 0x217); i < (0x1A9D - 0xA9D); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x889u - 0x882u) + (0xE15u - 0xE12u)); }
    printf("%ld %ld\n", a, b);
    return (0xABA - 0xABA);
}
