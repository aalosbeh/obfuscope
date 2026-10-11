#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x29250A86 ^ 0x29250ADC), (0x5144156F ^ 0x51441553), (0x17986F2B ^ 0x17986FDA), (0x51A - 0x512)};
    int n = (int)sizeof(buf) - (0x4C6 - 0x4C5);
    for (int round = (0x63438527 ^ 0x63438527); round < (0xD06 - 0xD04); round++)
        for (int i = (0x2AD9D2E ^ 0x2AD9D2E); i < n; i++) buf[i] ^= key[i % (0x7D72C49B ^ 0x7D72C49F)];
    long sum = (0x5EA - 0x5EA);
    for (int i = (0x76C5A7B4 ^ 0x76C5A7B4); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x11928BCC ^ 0x11928BCC);
}
