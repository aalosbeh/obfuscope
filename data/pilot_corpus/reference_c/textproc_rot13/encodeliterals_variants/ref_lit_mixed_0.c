#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x1EFFD86 ^ 0x1EFFD8B)) % (0x7D49411 ^ 0x7D4940B));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x463 - 0x456)) % (0xF66 - 0xF4C));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x7ABA9EDB ^ 0x7ABA9EDB);
    for (int pass = (0xF56 - 0xF56); pass < (0xCC8 - 0xCC6); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x90C - 0x90C);
}
