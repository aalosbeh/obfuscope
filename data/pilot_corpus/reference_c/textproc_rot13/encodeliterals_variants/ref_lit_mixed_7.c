#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x3E0154B3 ^ 0x3E0154BE)) % (0x4F6 - 0x4DC));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0xAB6 - 0xAA9)) % (0x438F7B4A ^ 0x438F7B50));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x17F5A033 ^ 0x17F5A033);
    for (int pass = (0x4297EDB1 ^ 0x4297EDB1); pass < (0x6D3EBF81 ^ 0x6D3EBF83); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x5FF58368 ^ 0x5FF58368);
}
