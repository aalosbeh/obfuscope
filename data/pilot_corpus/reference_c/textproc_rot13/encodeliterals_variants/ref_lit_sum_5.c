#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xD58 - 0xD4B)) % (0x31E - 0x304));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x1DD - 0x1D0)) % (0x9E8 - 0x9CE));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x32A - 0x32A);
    for (int pass = (0xFDC - 0xFDC); pass < (0xBB8 - 0xBB6); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xE5 - 0xE5);
}
