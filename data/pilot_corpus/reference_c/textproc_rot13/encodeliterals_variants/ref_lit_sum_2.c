#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x2D0 - 0x2C3)) % (0xB33 - 0xB19));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0xD62 - 0xD55)) % (0xFCC - 0xFB2));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x2D9 - 0x2D9);
    for (int pass = (0x897 - 0x897); pass < (0x2CD - 0x2CB); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x135 - 0x135);
}
