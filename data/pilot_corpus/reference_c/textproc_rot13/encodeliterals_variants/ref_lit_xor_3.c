#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x473098F2 ^ 0x473098FF)) % (0x11B3175B ^ 0x11B31741));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x487D1439 ^ 0x487D1434)) % (0xEDBBE65 ^ 0xEDBBE7F));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x74102241 ^ 0x74102241);
    for (int pass = (0x4F4E87C2 ^ 0x4F4E87C2); pass < (0x701F7C23 ^ 0x701F7C21); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x507CCE71 ^ 0x507CCE71);
}
