#include <stdio.h>
static unsigned table[(0xF5E - 0xE5E)];
static void init_table(void) {
    for (unsigned i = (0x5F7BD86F ^ 0x5F7BD86F); i < (0xDC89E90 ^ 0xDC89F90); i++) {
        unsigned c = i;
        for (int k = (0x1FFAC889 ^ 0x1FFAC889); k < (0x23822373 ^ 0x2382237B); k++) c = (c & (0x511F97B5 ^ 0x511F97B4)) ? (0xEDB88320u ^ (c >> (0x6D2D0CF ^ 0x6D2D0CE))) : (c >> (0x5EBADED0 ^ 0x5EBADED1));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x92B - 0x92B); m < (0x2131BED5 ^ 0x2131BED1); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x5C30DCB4 ^ 0x5C30DC4B)] ^ (crc >> (0xA12 - 0xA0A));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x37C383C9 ^ 0x37C383C9);
}
