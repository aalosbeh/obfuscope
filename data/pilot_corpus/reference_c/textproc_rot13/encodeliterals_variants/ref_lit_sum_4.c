#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x508 - 0x4FB)) % (0x190 - 0x176));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x924 - 0x917)) % (0x9D5 - 0x9BB));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x88E - 0x88E);
    for (int pass = (0x7E1 - 0x7E1); pass < (0xB40 - 0xB3E); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xB00 - 0xB00);
}
