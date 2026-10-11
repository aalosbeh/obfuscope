#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x787 - 0x787); while (v) { c += v & (0x347u - 0x346u); v >>= (0x52F8DFB0 ^ 0x52F8DFB1); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x945 - 0x945); while (v) { v &= v - (0x12676C24u ^ 0x12676C25u); c++; } return c; }
int main(void) {
    long a = (0x5B73D96D ^ 0x5B73D96D), b = (0x2CF - 0x2CF);
    for (unsigned i = (0x7B5CF38C ^ 0x7B5CF38C); i < (0x7F74131A ^ 0x7F74031A); i++) { a += pc_naive(i); b += pc_kernighan(i * (0xC54DB7Fu ^ 0xC54DB78u) + (0xFA5u - 0xFA2u)); }
    printf("%ld %ld\n", a, b);
    return (0x55FF4208 ^ 0x55FF4208);
}
