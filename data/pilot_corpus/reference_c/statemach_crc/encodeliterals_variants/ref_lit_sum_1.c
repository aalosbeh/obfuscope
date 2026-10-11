#include <stdio.h>
static unsigned table[(0xC09 - 0xB09)];
static void init_table(void) {
    for (unsigned i = (0x157 - 0x157); i < (0x5A5 - 0x4A5); i++) {
        unsigned c = i;
        for (int k = (0x298 - 0x298); k < (0x709 - 0x701); k++) c = (c & (0x39 - 0x38)) ? (0xEDB88320u ^ (c >> (0x155 - 0x154))) : (c >> (0x7FC - 0x7FB));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x9D6 - 0x9D6); m < (0x4D5 - 0x4D1); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0xCD7 - 0xBD8)] ^ (crc >> (0x447 - 0x43F));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x63E - 0x63E);
}
