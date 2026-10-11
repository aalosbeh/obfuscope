#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x29B - 0x29B); while (v) { c += v & (0x70740809u ^ 0x70740808u); v >>= (0xE48 - 0xE47); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x6A8 - 0x6A8); while (v) { v &= v - (0xF30u - 0xF2Fu); c++; } return c; }
int main(void) {
    long a = (0xDCE - 0xDCE), b = (0x6641A025 ^ 0x6641A025);
    for (unsigned i = (0x734A3FBA ^ 0x734A3FBA); i < (0x7A96A2C8 ^ 0x7A96B2C8); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x22Du - 0x226u) + (0x285C0BE7u ^ 0x285C0BE4u)); }
    printf("%ld %ld\n", a, b);
    return (0xBF6 - 0xBF6);
}
