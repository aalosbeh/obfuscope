#include <stdio.h>
static unsigned table[(0xB08 - 0xA08)];
static void init_table(void) {
    for (unsigned i = (0xEF8 - 0xEF8); i < (0x542 - 0x442); i++) {
        unsigned c = i;
        for (int k = (0x13E - 0x13E); k < (0x400 - 0x3F8); k++) c = (c & (0xBAA - 0xBA9)) ? (0xEDB88320u ^ (c >> (0x87F - 0x87E))) : (c >> (0x8B - 0x8A));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x2C7 - 0x2C7); m < (0xFD6 - 0xFD2); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0xBD7 - 0xAD8)] ^ (crc >> (0x299 - 0x291));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xD94 - 0xD94);
}
