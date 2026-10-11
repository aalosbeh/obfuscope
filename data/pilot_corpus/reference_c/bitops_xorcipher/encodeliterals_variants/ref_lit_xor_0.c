#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x7F4D962E ^ 0x7F4D9674), (0x2C4DBBDC ^ 0x2C4DBBE0), (0x4F3442A9 ^ 0x4F344258), (0x1D207B79 ^ 0x1D207B71)};
    int n = (int)sizeof(buf) - (0x261001E9 ^ 0x261001E8);
    for (int round = (0x142CDCE2 ^ 0x142CDCE2); round < (0x3F613F7B ^ 0x3F613F79); round++)
        for (int i = (0x61284ED4 ^ 0x61284ED4); i < n; i++) buf[i] ^= key[i % (0x2DCDD887 ^ 0x2DCDD883)];
    long sum = (0x19A93967 ^ 0x19A93967);
    for (int i = (0x2C12E67F ^ 0x2C12E67F); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x3364FDEE ^ 0x3364FDEE);
}
