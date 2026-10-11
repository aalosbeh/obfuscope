#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x560 - 0x506), (0x41B - 0x3DF), (0x1B4 - 0xC3), (0x7A4 - 0x79C)};
    int n = (int)sizeof(buf) - (0x87C - 0x87B);
    for (int round = (0xE87 - 0xE87); round < (0x2E9 - 0x2E7); round++)
        for (int i = (0xD33 - 0xD33); i < n; i++) buf[i] ^= key[i % (0xA7A - 0xA76)];
    long sum = (0x14E - 0x14E);
    for (int i = (0x86F - 0x86F); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0xE3D - 0xE3D);
}
