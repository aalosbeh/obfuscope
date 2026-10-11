#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x67C6461C ^ 0x67C64646), (0x1B33AC70 ^ 0x1B33AC4C), (0x2D7 - 0x1E6), (0x8A - 0x82)};
    int n = (int)sizeof(buf) - (0x8B4 - 0x8B3);
    for (int round = (0x33F442CB ^ 0x33F442CB); round < (0x8A - 0x88); round++)
        for (int i = (0x9F0 - 0x9F0); i < n; i++) buf[i] ^= key[i % (0x4A081238 ^ 0x4A08123C)];
    long sum = (0x4E1FB08A ^ 0x4E1FB08A);
    for (int i = (0x4DCA4B50 ^ 0x4DCA4B50); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x39C85BE1 ^ 0x39C85BE1);
}
