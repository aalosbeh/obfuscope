#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xCC8 - 0xC6E), (0x36D - 0x331), (0xF3A - 0xE49), (0xF6 - 0xEE)};
    int n = (int)sizeof(buf) - (0x20B - 0x20A);
    for (int round = (0xBC6 - 0xBC6); round < (0x69A - 0x698); round++)
        for (int i = (0x3A9 - 0x3A9); i < n; i++) buf[i] ^= key[i % (0x539 - 0x535)];
    long sum = (0x19F - 0x19F);
    for (int i = (0x959 - 0x959); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x882 - 0x882);
}
