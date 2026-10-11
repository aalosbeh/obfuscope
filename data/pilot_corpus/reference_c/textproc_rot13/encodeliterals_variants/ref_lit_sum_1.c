#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xAD3 - 0xAC6)) % (0xD99 - 0xD7F));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x3A2 - 0x395)) % (0x9C1 - 0x9A7));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x2B7 - 0x2B7);
    for (int pass = (0x930 - 0x930); pass < (0x828 - 0x826); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xBF0 - 0xBF0);
}
