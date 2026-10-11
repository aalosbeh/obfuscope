#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x56E - 0x561)) % (0x71BE8AAD ^ 0x71BE8AB7));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x270 - 0x263)) % (0x4CC4AE61 ^ 0x4CC4AE7B));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x75CFA4CF ^ 0x75CFA4CF);
    for (int pass = (0x1B8B3FA2 ^ 0x1B8B3FA2); pass < (0xF73F284 ^ 0xF73F286); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x213B4FAF ^ 0x213B4FAF);
}
