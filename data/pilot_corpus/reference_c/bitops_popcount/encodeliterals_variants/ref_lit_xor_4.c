#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x71577A42 ^ 0x71577A42); while (v) { c += v & (0x7C5F57E9u ^ 0x7C5F57E8u); v >>= (0x3AA35669 ^ 0x3AA35668); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x4668D538 ^ 0x4668D538); while (v) { v &= v - (0x5B3B8F7Bu ^ 0x5B3B8F7Au); c++; } return c; }
int main(void) {
    long a = (0x71985D96 ^ 0x71985D96), b = (0x7E89B40C ^ 0x7E89B40C);
    for (unsigned i = (0x4EB3B0AB ^ 0x4EB3B0AB); i < (0x71BACC01 ^ 0x71BADC01); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x6FA6824Fu ^ 0x6FA68248u) + (0x57617C6Eu ^ 0x57617C6Du)); }
    printf("%ld %ld\n", a, b);
    return (0x7470F194 ^ 0x7470F194);
}
