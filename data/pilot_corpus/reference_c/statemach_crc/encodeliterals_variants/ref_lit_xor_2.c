#include <stdio.h>
static unsigned table[(0x512A1674 ^ 0x512A1774)];
static void init_table(void) {
    for (unsigned i = (0x6F8AFFF6 ^ 0x6F8AFFF6); i < (0x357CC57A ^ 0x357CC47A); i++) {
        unsigned c = i;
        for (int k = (0x762F7355 ^ 0x762F7355); k < (0x75FCCFF2 ^ 0x75FCCFFA); k++) c = (c & (0x51E1AFD3 ^ 0x51E1AFD2)) ? (0xEDB88320u ^ (c >> (0x43D2FBCC ^ 0x43D2FBCD))) : (c >> (0x57BD530C ^ 0x57BD530D));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x60746C95 ^ 0x60746C95); m < (0x658EF85C ^ 0x658EF858); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x1EB5FBFF ^ 0x1EB5FB00)] ^ (crc >> (0x70FF280E ^ 0x70FF2806));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x738A2BB ^ 0x738A2BB);
}
