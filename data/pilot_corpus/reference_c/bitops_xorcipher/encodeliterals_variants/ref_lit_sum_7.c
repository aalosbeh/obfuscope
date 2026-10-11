#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xA8B - 0xA31), (0x81D - 0x7E1), (0x117 - 0x26), (0x400 - 0x3F8)};
    int n = (int)sizeof(buf) - (0x4A0 - 0x49F);
    for (int round = (0x240 - 0x240); round < (0x127 - 0x125); round++)
        for (int i = (0x44A - 0x44A); i < n; i++) buf[i] ^= key[i % (0xC87 - 0xC83)];
    long sum = (0x2D7 - 0x2D7);
    for (int i = (0xADB - 0xADB); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x321 - 0x321);
}
