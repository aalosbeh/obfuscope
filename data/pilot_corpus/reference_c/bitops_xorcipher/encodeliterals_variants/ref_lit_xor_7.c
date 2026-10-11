#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x19058365 ^ 0x1905833F), (0x41D7723B ^ 0x41D77207), (0x9CDB62B ^ 0x9CDB6DA), (0x73ADA92C ^ 0x73ADA924)};
    int n = (int)sizeof(buf) - (0x4FA8C385 ^ 0x4FA8C384);
    for (int round = (0x63535E3B ^ 0x63535E3B); round < (0x3BBA0BC5 ^ 0x3BBA0BC7); round++)
        for (int i = (0x5BDC7683 ^ 0x5BDC7683); i < n; i++) buf[i] ^= key[i % (0x40F84E9C ^ 0x40F84E98)];
    long sum = (0x6A4BEAED ^ 0x6A4BEAED);
    for (int i = (0x162C7968 ^ 0x162C7968); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x704ECB52 ^ 0x704ECB52);
}
