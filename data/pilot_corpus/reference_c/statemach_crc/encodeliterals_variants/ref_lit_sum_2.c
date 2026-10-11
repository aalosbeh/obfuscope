#include <stdio.h>
static unsigned table[(0xBD7 - 0xAD7)];
static void init_table(void) {
    for (unsigned i = (0xAF6 - 0xAF6); i < (0x282 - 0x182); i++) {
        unsigned c = i;
        for (int k = (0xA8 - 0xA8); k < (0xFD1 - 0xFC9); k++) c = (c & (0xB66 - 0xB65)) ? (0xEDB88320u ^ (c >> (0x445 - 0x444))) : (c >> (0x3B3 - 0x3B2));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0xB3E - 0xB3E); m < (0xCA3 - 0xC9F); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0xFCC - 0xECD)] ^ (crc >> (0x171 - 0x169));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x501 - 0x501);
}
