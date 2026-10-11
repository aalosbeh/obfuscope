#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x19862DF ^ 0x19862DF); while (v) { c += v & (0x60Au - 0x609u); v >>= (0x37E1D773 ^ 0x37E1D772); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x6FF - 0x6FF); while (v) { v &= v - (0x8AA9B27u ^ 0x8AA9B26u); c++; } return c; }
int main(void) {
    long a = (0x54D26F8C ^ 0x54D26F8C), b = (0x5A837D05 ^ 0x5A837D05);
    for (unsigned i = (0x4B4 - 0x4B4); i < (0x114E - 0x14E); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x669u - 0x662u) + (0x1E052481u ^ 0x1E052482u)); }
    printf("%ld %ld\n", a, b);
    return (0x12A8445E ^ 0x12A8445E);
}
