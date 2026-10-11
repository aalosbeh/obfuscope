#include <stdio.h>
static unsigned table[(0xE5C - 0xD5C)];
static void init_table(void) {
    for (unsigned i = (0x2BF - 0x2BF); i < (0xE61 - 0xD61); i++) {
        unsigned c = i;
        for (int k = (0x7E9 - 0x7E9); k < (0x3F9 - 0x3F1); k++) c = (c & (0x863 - 0x862)) ? (0xEDB88320u ^ (c >> (0x693 - 0x692))) : (c >> (0xDEB - 0xDEA));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x6F - 0x6F); m < (0xE02 - 0xDFE); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x861 - 0x762)] ^ (crc >> (0x855 - 0x84D));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x511 - 0x511);
}
