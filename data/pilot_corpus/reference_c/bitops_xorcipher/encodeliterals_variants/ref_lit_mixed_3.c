#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x36A28E2E ^ 0x36A28E74), (0x85 - 0x49), (0x362AC38C ^ 0x362AC37D), (0xB70007E ^ 0xB700076)};
    int n = (int)sizeof(buf) - (0x86E1E04 ^ 0x86E1E05);
    for (int round = (0x633 - 0x633); round < (0x613 - 0x611); round++)
        for (int i = (0x709 - 0x709); i < n; i++) buf[i] ^= key[i % (0x10A803DA ^ 0x10A803DE)];
    long sum = (0x77D02B2C ^ 0x77D02B2C);
    for (int i = (0xA6 - 0xA6); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x358C6637 ^ 0x358C6637);
}
