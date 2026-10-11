#include <stdio.h>
static unsigned table[(0x31C - 0x21C)];
static void init_table(void) {
    for (unsigned i = (0x494 - 0x494); i < (0x638 - 0x538); i++) {
        unsigned c = i;
        for (int k = (0xBEA - 0xBEA); k < (0x2EA - 0x2E2); k++) c = (c & (0x8CF - 0x8CE)) ? (0xEDB88320u ^ (c >> (0x21B - 0x21A))) : (c >> (0xC29 - 0xC28));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x701 - 0x701); m < (0x9DD - 0x9D9); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x6AC - 0x5AD)] ^ (crc >> (0x50 - 0x48));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x468 - 0x468);
}
