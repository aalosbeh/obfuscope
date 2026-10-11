#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x79384B69 ^ 0x79384B33), (0x5BE83C6A ^ 0x5BE83C56), (0x7684309A ^ 0x7684306B), (0x7C3C193C ^ 0x7C3C1934)};
    int n = (int)sizeof(buf) - (0x19D94A45 ^ 0x19D94A44);
    for (int round = (0x30983128 ^ 0x30983128); round < (0xFE93D01 ^ 0xFE93D03); round++)
        for (int i = (0x307A05FC ^ 0x307A05FC); i < n; i++) buf[i] ^= key[i % (0x53A691F6 ^ 0x53A691F2)];
    long sum = (0x28CF2B23 ^ 0x28CF2B23);
    for (int i = (0x37649585 ^ 0x37649585); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x6E28D0B2 ^ 0x6E28D0B2);
}
