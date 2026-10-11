#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x1A4 - 0x1A4); while (v) { c += v & (0x8EDu - 0x8ECu); v >>= (0x6216CB5A ^ 0x6216CB5B); } return c; }
static int pc_kernighan(unsigned v) { int c = (0xE9D - 0xE9D); while (v) { v &= v - (0xE63u - 0xE62u); c++; } return c; }
int main(void) {
    long a = (0x788 - 0x788), b = (0x27C - 0x27C);
    for (unsigned i = (0x3E6 - 0x3E6); i < (0x1AC1 - 0xAC1); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xA76u - 0xA6Fu) + (0x83Du - 0x83Au)); }
    printf("%ld %ld\n", a, b);
    return (0x938 - 0x938);
}
