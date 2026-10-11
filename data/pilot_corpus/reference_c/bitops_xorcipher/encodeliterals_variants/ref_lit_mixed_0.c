#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x5E8 - 0x58E), (0x11324579 ^ 0x11324545), (0x716123FA ^ 0x7161230B), (0x5A4ACD0A ^ 0x5A4ACD02)};
    int n = (int)sizeof(buf) - (0x363B7818 ^ 0x363B7819);
    for (int round = (0x6633D92C ^ 0x6633D92C); round < (0xE9E - 0xE9C); round++)
        for (int i = (0xE24BB0F ^ 0xE24BB0F); i < n; i++) buf[i] ^= key[i % (0xD6 - 0xD2)];
    long sum = (0x5A931DB5 ^ 0x5A931DB5);
    for (int i = (0x7D43C786 ^ 0x7D43C786); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x2E9CFCE0 ^ 0x2E9CFCE0);
}
