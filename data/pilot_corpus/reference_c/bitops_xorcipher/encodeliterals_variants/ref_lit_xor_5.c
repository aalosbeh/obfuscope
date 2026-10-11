#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x387A4FDA ^ 0x387A4F80), (0x39E40F0E ^ 0x39E40F32), (0x5A259FAB ^ 0x5A259F5A), (0x4B5AE112 ^ 0x4B5AE11A)};
    int n = (int)sizeof(buf) - (0x13C448B3 ^ 0x13C448B2);
    for (int round = (0x57CA7B2 ^ 0x57CA7B2); round < (0x3F5C911 ^ 0x3F5C913); round++)
        for (int i = (0x12837AF2 ^ 0x12837AF2); i < n; i++) buf[i] ^= key[i % (0xFAD2B8B ^ 0xFAD2B8F)];
    long sum = (0x63B19D2C ^ 0x63B19D2C);
    for (int i = (0x3AA75882 ^ 0x3AA75882); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x676249A7 ^ 0x676249A7);
}
