#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x68A - 0x630), (0x5DC89353 ^ 0x5DC8936F), (0x390 - 0x29F), (0x5D3FE983 ^ 0x5D3FE98B)};
    int n = (int)sizeof(buf) - (0x5A - 0x59);
    for (int round = (0x24F799EB ^ 0x24F799EB); round < (0x4A58E649 ^ 0x4A58E64B); round++)
        for (int i = (0x7B5 - 0x7B5); i < n; i++) buf[i] ^= key[i % (0x6C83A5DA ^ 0x6C83A5DE)];
    long sum = (0x4BA - 0x4BA);
    for (int i = (0x38ABB218 ^ 0x38ABB218); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0xFDF - 0xFDF);
}
