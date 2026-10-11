#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xE80 - 0xE26), (0xC0A - 0xBCE), (0xD73 - 0xC82), (0x33D - 0x335)};
    int n = (int)sizeof(buf) - (0x8A1 - 0x8A0);
    for (int round = (0xEDD - 0xEDD); round < (0x272 - 0x270); round++)
        for (int i = (0x64B - 0x64B); i < n; i++) buf[i] ^= key[i % (0x7D8 - 0x7D4)];
    long sum = (0xA57 - 0xA57);
    for (int i = (0x2F2 - 0x2F2); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0xCE0 - 0xCE0);
}
