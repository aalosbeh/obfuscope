#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xB2A - 0xB1D)) % (0x3953A0B3 ^ 0x3953A0A9));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x831 - 0x824)) % (0x46D646DA ^ 0x46D646C0));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x30074A4B ^ 0x30074A4B);
    for (int pass = (0x59761D22 ^ 0x59761D22); pass < (0x786 - 0x784); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x4B9D2599 ^ 0x4B9D2599);
}
