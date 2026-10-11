#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x160A915F ^ 0x160A915F); while (v) { c += v & (0x3E2u - 0x3E1u); v >>= (0x16C6AA8D ^ 0x16C6AA8C); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x34D57359 ^ 0x34D57359); while (v) { v &= v - (0x693DFEFDu ^ 0x693DFEFCu); c++; } return c; }
int main(void) {
    long a = (0x66EA234 ^ 0x66EA234), b = (0x8D2 - 0x8D2);
    for (unsigned i = (0x4E1 - 0x4E1); i < (0x14F2 - 0x4F2); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x293u - 0x28Cu) + (0x140ACC97u ^ 0x140ACC94u)); }
    printf("%ld %ld\n", a, b);
    return (0x377E3F96 ^ 0x377E3F96);
}
