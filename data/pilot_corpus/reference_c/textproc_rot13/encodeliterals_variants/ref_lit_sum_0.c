#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x42D - 0x420)) % (0x892 - 0x878));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0xB27 - 0xB1A)) % (0x995 - 0x97B));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0xA6 - 0xA6);
    for (int pass = (0x8F3 - 0x8F3); pass < (0x9E3 - 0x9E1); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x1CB - 0x1CB);
}
