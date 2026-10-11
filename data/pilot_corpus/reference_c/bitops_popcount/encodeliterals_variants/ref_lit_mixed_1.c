#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x977 - 0x977); while (v) { c += v & (0xBD9u - 0xBD8u); v >>= (0xB93 - 0xB92); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x47E15390 ^ 0x47E15390); while (v) { v &= v - (0x2C559285u ^ 0x2C559284u); c++; } return c; }
int main(void) {
    long a = (0xD6DF7E2 ^ 0xD6DF7E2), b = (0xBE1 - 0xBE1);
    for (unsigned i = (0xC38 - 0xC38); i < (0x7B36A643 ^ 0x7B36B643); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x76Eu - 0x767u) + (0x7A97217Eu ^ 0x7A97217Du)); }
    printf("%ld %ld\n", a, b);
    return (0x63 - 0x63);
}
