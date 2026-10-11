#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xE6A4D7 ^ 0xE6A48D), (0x72CD4EF1 ^ 0x72CD4ECD), (0x44F65DF7 ^ 0x44F65D06), (0x2D3368A8 ^ 0x2D3368A0)};
    int n = (int)sizeof(buf) - (0xCC74352 ^ 0xCC74353);
    for (int round = (0x546C79DE ^ 0x546C79DE); round < (0x30AE32ED ^ 0x30AE32EF); round++)
        for (int i = (0x19F809EE ^ 0x19F809EE); i < n; i++) buf[i] ^= key[i % (0x4990B593 ^ 0x4990B597)];
    long sum = (0x52C8200E ^ 0x52C8200E);
    for (int i = (0x66047B7B ^ 0x66047B7B); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x1702F854 ^ 0x1702F854);
}
