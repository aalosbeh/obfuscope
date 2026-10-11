#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x785F850D ^ 0x785F850D); while (v) { c += v & (0x449AD257u ^ 0x449AD256u); v >>= (0x6AC712DF ^ 0x6AC712DE); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x7847957D ^ 0x7847957D); while (v) { v &= v - (0x4CF930E8u ^ 0x4CF930E9u); c++; } return c; }
int main(void) {
    long a = (0x7A108EA ^ 0x7A108EA), b = (0x2090D045 ^ 0x2090D045);
    for (unsigned i = (0x14F2D94C ^ 0x14F2D94C); i < (0x7ED0E599 ^ 0x7ED0F599); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x6FB1B91u ^ 0x6FB1B96u) + (0x2986A52Eu ^ 0x2986A52Du)); }
    printf("%ld %ld\n", a, b);
    return (0x770E3F0A ^ 0x770E3F0A);
}
