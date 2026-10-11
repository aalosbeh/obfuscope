#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x3E3 - 0x389), (0xB9 - 0x7D), (0x9E6 - 0x8F5), (0xA65 - 0xA5D)};
    int n = (int)sizeof(buf) - (0xD22 - 0xD21);
    for (int round = (0xCB8 - 0xCB8); round < (0x86E - 0x86C); round++)
        for (int i = (0x6E2 - 0x6E2); i < n; i++) buf[i] ^= key[i % (0x429 - 0x425)];
    long sum = (0x9EF - 0x9EF);
    for (int i = (0xDED - 0xDED); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x55E - 0x55E);
}
