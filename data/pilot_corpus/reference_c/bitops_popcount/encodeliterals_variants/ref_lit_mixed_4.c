#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x3C1FBCA3 ^ 0x3C1FBCA3); while (v) { c += v & (0x3901904u ^ 0x3901905u); v >>= (0x7C33041 ^ 0x7C33040); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x12A9C5A8 ^ 0x12A9C5A8); while (v) { v &= v - (0x21Eu - 0x21Du); c++; } return c; }
int main(void) {
    long a = (0x73FB1882 ^ 0x73FB1882), b = (0xF6D - 0xF6D);
    for (unsigned i = (0xEE3 - 0xEE3); i < (0x1081 - 0x81); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xC9Eu - 0xC97u) + (0xCCFu - 0xCCCu)); }
    printf("%ld %ld\n", a, b);
    return (0xE4A - 0xE4A);
}
