#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x12270BBB ^ 0x12270BB6)) % (0x4D7421E0 ^ 0x4D7421FA));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x39337CC9 ^ 0x39337CC4)) % (0x4C678251 ^ 0x4C67824B));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x6CF4E491 ^ 0x6CF4E491);
    for (int pass = (0x7D7FFCDB ^ 0x7D7FFCDB); pass < (0x37216B2 ^ 0x37216B0); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x7FCF9585 ^ 0x7FCF9585);
}
