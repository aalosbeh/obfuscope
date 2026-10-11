#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x63561223 ^ 0x63561279), (0x226FCD08 ^ 0x226FCD34), (0x46F84E79 ^ 0x46F84E88), (0x4D08BF11 ^ 0x4D08BF19)};
    int n = (int)sizeof(buf) - (0x1F575EB6 ^ 0x1F575EB7);
    for (int round = (0x40F4BB28 ^ 0x40F4BB28); round < (0x7346782D ^ 0x7346782F); round++)
        for (int i = (0x4FCF01DE ^ 0x4FCF01DE); i < n; i++) buf[i] ^= key[i % (0x706B7ADD ^ 0x706B7AD9)];
    long sum = (0x4EEBAB82 ^ 0x4EEBAB82);
    for (int i = (0x4AF8243 ^ 0x4AF8243); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0xC517567 ^ 0xC517567);
}
