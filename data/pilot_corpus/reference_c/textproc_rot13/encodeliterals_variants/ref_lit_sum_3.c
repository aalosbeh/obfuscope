#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0xD8F - 0xD82)) % (0x9F1 - 0x9D7));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x86F - 0x862)) % (0x6ED - 0x6D3));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0xD08 - 0xD08);
    for (int pass = (0x945 - 0x945); pass < (0x6E2 - 0x6E0); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x4AA - 0x4AA);
}
