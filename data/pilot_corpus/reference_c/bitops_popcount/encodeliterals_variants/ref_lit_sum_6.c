#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0xF90 - 0xF90); while (v) { c += v & (0xC2Eu - 0xC2Du); v >>= (0x7EC - 0x7EB); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x40F - 0x40F); while (v) { v &= v - (0x533u - 0x532u); c++; } return c; }
int main(void) {
    long a = (0x3DD - 0x3DD), b = (0x76D - 0x76D);
    for (unsigned i = (0x770 - 0x770); i < (0x13E1 - 0x3E1); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xA1u - 0x9Au) + (0x18Au - 0x187u)); }
    printf("%ld %ld\n", a, b);
    return (0xB10 - 0xB10);
}
