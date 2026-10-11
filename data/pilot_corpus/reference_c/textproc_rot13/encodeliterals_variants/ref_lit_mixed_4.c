#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x4C39EEF4 ^ 0x4C39EEF9)) % (0x62F3B55B ^ 0x62F3B541));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0xB0D - 0xB00)) % (0x25DEDD07 ^ 0x25DEDD1D));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x5B134883 ^ 0x5B134883);
    for (int pass = (0x78FCD82D ^ 0x78FCD82D); pass < (0x10B5DEB5 ^ 0x10B5DEB7); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x418D123A ^ 0x418D123A);
}
