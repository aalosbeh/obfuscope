#include <stdio.h>
static unsigned table[(0x3C8 - 0x2C8)];
static void init_table(void) {
    for (unsigned i = (0xF96 - 0xF96); i < (0xDDB - 0xCDB); i++) {
        unsigned c = i;
        for (int k = (0xB5A - 0xB5A); k < (0x93C - 0x934); k++) c = (c & (0x353 - 0x352)) ? (0xEDB88320u ^ (c >> (0xD71 - 0xD70))) : (c >> (0x950 - 0x94F));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0xD7 - 0xD7); m < (0xA8C - 0xA88); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x77F - 0x680)] ^ (crc >> (0x100 - 0xF8));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x4C8 - 0x4C8);
}
