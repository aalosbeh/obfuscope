#include <stdio.h>
static unsigned table[(0x4926158B ^ 0x4926148B)];
static void init_table(void) {
    for (unsigned i = (0x41ADF67B ^ 0x41ADF67B); i < (0x57776EC1 ^ 0x57776FC1); i++) {
        unsigned c = i;
        for (int k = (0x6F8E9013 ^ 0x6F8E9013); k < (0x3FCE8D63 ^ 0x3FCE8D6B); k++) c = (c & (0x4D20100E ^ 0x4D20100F)) ? (0xEDB88320u ^ (c >> (0x18612D3 ^ 0x18612D2))) : (c >> (0x5211BDBC ^ 0x5211BDBD));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x4AF272FF ^ 0x4AF272FF); m < (0x18D2D56 ^ 0x18D2D52); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x4F3AC0FE ^ 0x4F3AC001)] ^ (crc >> (0x5B8828A2 ^ 0x5B8828AA));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xB6F680A ^ 0xB6F680A);
}
