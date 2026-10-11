#include <stdio.h>
static unsigned table[(0x632 - 0x532)];
static void init_table(void) {
    for (unsigned i = (0xEB9 - 0xEB9); i < (0x448 - 0x348); i++) {
        unsigned c = i;
        for (int k = (0x575 - 0x575); k < (0x85B - 0x853); k++) c = (c & (0xAFF - 0xAFE)) ? (0xEDB88320u ^ (c >> (0x747 - 0x746))) : (c >> (0x31D - 0x31C));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x82B - 0x82B); m < (0x270 - 0x26C); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x10EB - 0xFEC)] ^ (crc >> (0x418 - 0x410));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x624 - 0x624);
}
