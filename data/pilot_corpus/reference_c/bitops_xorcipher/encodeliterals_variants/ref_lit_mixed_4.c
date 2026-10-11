#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x4E0 - 0x486), (0x3FF - 0x3C3), (0x48928D00 ^ 0x48928DF1), (0x3F01867E ^ 0x3F018676)};
    int n = (int)sizeof(buf) - (0x5 - 0x4);
    for (int round = (0x5A9B1DCC ^ 0x5A9B1DCC); round < (0x1B2 - 0x1B0); round++)
        for (int i = (0x421 - 0x421); i < n; i++) buf[i] ^= key[i % (0x199B1C4 ^ 0x199B1C0)];
    long sum = (0xC19 - 0xC19);
    for (int i = (0x81B - 0x81B); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x3DC - 0x3DC);
}
