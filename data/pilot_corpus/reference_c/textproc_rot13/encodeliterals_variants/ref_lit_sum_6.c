#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xD96 - 0xD89)) % (0xBF4 - 0xBDA));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0xE27 - 0xE1A)) % (0x412 - 0x3F8));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x5A5 - 0x5A5);
    for (int pass = (0x64F - 0x64F); pass < (0x173 - 0x171); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xC82 - 0xC82);
}
