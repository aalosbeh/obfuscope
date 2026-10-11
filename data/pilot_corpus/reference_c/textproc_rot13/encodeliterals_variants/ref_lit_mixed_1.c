#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x6F0 - 0x6E3)) % (0x7275957F ^ 0x72759565));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x785EDE6B ^ 0x785EDE66)) % (0x25 - 0xB));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x8DE - 0x8DE);
    for (int pass = (0x67650FC0 ^ 0x67650FC0); pass < (0x1FAB3A25 ^ 0x1FAB3A27); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x4830B6DF ^ 0x4830B6DF);
}
