#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xAE - 0xA1)) % (0xB0D - 0xAF3));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0xAAB - 0xA9E)) % (0x4270BBB7 ^ 0x4270BBAD));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0xB9F - 0xB9F);
    for (int pass = (0x651 - 0x651); pass < (0x1B6 - 0x1B4); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x3D8 - 0x3D8);
}
