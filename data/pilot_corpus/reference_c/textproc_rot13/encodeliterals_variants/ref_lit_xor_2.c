#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + (0x5D595ADC ^ 0x5D595AD1)) % (0xC2CF468 ^ 0xC2CF472));
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + (0x3F29665A ^ 0x3F296657)) % (0x6121E315 ^ 0x6121E30F));
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = (0x6F27ED8D ^ 0x6F27ED8D);
    for (int pass = (0x51A5123B ^ 0x51A5123B); pass < (0x5947F8F0 ^ 0x5947F8F2); pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return (0x4CD03DAC ^ 0x4CD03DAC);
}
