#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xD7B36CC ^ 0xD7B36C1)) % (0x1133517E ^ 0x11335164));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x47935C31 ^ 0x47935C3C)) % (0x2787B639 ^ 0x2787B623));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x174F5DC1 ^ 0x174F5DC1);
    for (int pass = (0xF438049 ^ 0xF438049); pass < (0x7967C9F ^ 0x7967C9D); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0xE1FE528 ^ 0xE1FE528);
}
