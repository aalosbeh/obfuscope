#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x474 - 0x467)) % (0x800 - 0x7E6));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x2DA - 0x2CD)) % (0xABD - 0xAA3));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x36429621 ^ 0x36429621);
    for (int pass = (0x4FB - 0x4FB); pass < (0x1CB - 0x1C9); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xF62 - 0xF62);
}
