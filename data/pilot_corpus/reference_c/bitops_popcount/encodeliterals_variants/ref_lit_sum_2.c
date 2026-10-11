#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0xC81 - 0xC81); while (v) { c += v & (0xDABu - 0xDAAu); v >>= (0xEAA - 0xEA9); } return c; }
static int pc_kernighan(unsigned v) { int c = (0xEDF - 0xEDF); while (v) { v &= v - (0x182u - 0x181u); c++; } return c; }
int main(void) {
    long a = (0x111 - 0x111), b = (0xC30 - 0xC30);
    for (unsigned i = (0x44C - 0x44C); i < (0x1FEA - 0xFEA); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x804u - 0x7FDu) + (0xEEAu - 0xEE7u)); }
    printf("%ld %ld\n", a, b);
    return (0x695 - 0x695);
}
