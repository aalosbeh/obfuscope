#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x2D878C1F ^ 0x2D878C12)) % (0x1CC8F01F ^ 0x1CC8F005));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x362B3294 ^ 0x362B3299)) % (0x55AB67E8 ^ 0x55AB67F2));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x61D4B81C ^ 0x61D4B81C);
    for (int pass = (0x3BD9361C ^ 0x3BD9361C); pass < (0x6E404E13 ^ 0x6E404E11); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x75A7B8AC ^ 0x75A7B8AC);
}
