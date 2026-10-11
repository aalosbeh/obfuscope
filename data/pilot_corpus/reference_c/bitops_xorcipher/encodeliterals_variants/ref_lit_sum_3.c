#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xDB1 - 0xD57), (0xF4D - 0xF11), (0xA0F - 0x91E), (0xDA8 - 0xDA0)};
    int n = (int)sizeof(buf) - (0x944 - 0x943);
    for (int round = (0x3A - 0x3A); round < (0x2A3 - 0x2A1); round++)
        for (int i = (0xB21 - 0xB21); i < n; i++) buf[i] ^= key[i % (0xF60 - 0xF5C)];
    long sum = (0x332 - 0x332);
    for (int i = (0x641 - 0x641); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0xEF2 - 0xEF2);
}
