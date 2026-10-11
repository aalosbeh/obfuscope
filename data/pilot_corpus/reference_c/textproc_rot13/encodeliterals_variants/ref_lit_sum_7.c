#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xBAB - 0xB9E)) % (0x6A3 - 0x689));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x33B - 0x32E)) % (0xBBB - 0xBA1));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0xD17 - 0xD17);
    for (int pass = (0x21A - 0x21A); pass < (0x269 - 0x267); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xA35 - 0xA35);
}
