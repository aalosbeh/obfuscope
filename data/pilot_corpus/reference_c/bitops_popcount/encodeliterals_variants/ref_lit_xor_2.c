#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x6DB51526 ^ 0x6DB51526); while (v) { c += v & (0xA6EFCDFu ^ 0xA6EFCDEu); v >>= (0x31D53754 ^ 0x31D53755); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x488EA623 ^ 0x488EA623); while (v) { v &= v - (0x2A81C26u ^ 0x2A81C27u); c++; } return c; }
int main(void) {
    long a = (0x185E79D6 ^ 0x185E79D6), b = (0x31301527 ^ 0x31301527);
    for (unsigned i = (0x2E07BDC6 ^ 0x2E07BDC6); i < (0x6A44997E ^ 0x6A44897E); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x21D7CF5Cu ^ 0x21D7CF5Bu) + (0x19FFDAA3u ^ 0x19FFDAA0u)); }
    printf("%ld %ld\n", a, b);
    return (0x5FC8C1AB ^ 0x5FC8C1AB);
}
