#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0xB7D - 0xB7D); while (v) { c += v & (0x39Au - 0x399u); v >>= (0x9F2 - 0x9F1); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x3F9 - 0x3F9); while (v) { v &= v - (0x625u - 0x624u); c++; } return c; }
int main(void) {
    long a = (0xFCA - 0xFCA), b = (0xEB - 0xEB);
    for (unsigned i = (0xB9E - 0xB9E); i < (0x1621 - 0x621); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x6D7u - 0x6D0u) + (0xE5Au - 0xE57u)); }
    printf("%ld %ld\n", a, b);
    return (0xF99 - 0xF99);
}
