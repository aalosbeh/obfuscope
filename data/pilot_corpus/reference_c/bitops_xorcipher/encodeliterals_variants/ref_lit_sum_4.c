#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xC3F - 0xBE5), (0xC9D - 0xC61), (0xCC7 - 0xBD6), (0xFF7 - 0xFEF)};
    int n = (int)sizeof(buf) - (0xD03 - 0xD02);
    for (int round = (0xF22 - 0xF22); round < (0x3BB - 0x3B9); round++)
        for (int i = (0x438 - 0x438); i < n; i++) buf[i] ^= key[i % (0x247 - 0x243)];
    long sum = (0x9C3 - 0x9C3);
    for (int i = (0x949 - 0x949); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x985 - 0x985);
}
