#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x53F48134 ^ 0x53F48139)) % (0x1306A51B ^ 0x1306A501));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x56E5EE2B ^ 0x56E5EE26)) % (0x509177B1 ^ 0x509177AB));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x37D16EBD ^ 0x37D16EBD);
    for (int pass = (0x12B75F0F ^ 0x12B75F0F); pass < (0x25587598 ^ 0x2558759A); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x63D94659 ^ 0x63D94659);
}
