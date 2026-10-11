#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x104E - 0xFF4), (0x971 - 0x935), (0x637 - 0x546), (0x40C - 0x404)};
    int n = (int)sizeof(buf) - (0xF2E - 0xF2D);
    for (int round = (0xC01 - 0xC01); round < (0xD7D - 0xD7B); round++)
        for (int i = (0xA3A - 0xA3A); i < n; i++) buf[i] ^= key[i % (0xBC - 0xB8)];
    long sum = (0xD14 - 0xD14);
    for (int i = (0x392 - 0x392); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0xD51 - 0xD51);
}
