#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x4C1DCA63 ^ 0x4C1DCA6E)) % (0x53DCEA30 ^ 0x53DCEA2A));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x57A49BD2 ^ 0x57A49BDF)) % (0x75E58F84 ^ 0x75E58F9E));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x52969196 ^ 0x52969196);
    for (int pass = (0x37421060 ^ 0x37421060); pass < (0x629BD8F2 ^ 0x629BD8F0); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x17A63E75 ^ 0x17A63E75);
}
