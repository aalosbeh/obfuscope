#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x4DE - 0x4DE); while (v) { c += v & (0xA2Eu - 0xA2Du); v >>= (0x451 - 0x450); } return c; }
static int pc_kernighan(unsigned v) { int c = (0xD83 - 0xD83); while (v) { v &= v - (0x4F4u - 0x4F3u); c++; } return c; }
int main(void) {
    long a = (0x231 - 0x231), b = (0x6F7 - 0x6F7);
    for (unsigned i = (0x4C7 - 0x4C7); i < (0x1853 - 0x853); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x6D6u - 0x6CFu) + (0x8D0u - 0x8CDu)); }
    printf("%ld %ld\n", a, b);
    return (0xC10 - 0xC10);
}
