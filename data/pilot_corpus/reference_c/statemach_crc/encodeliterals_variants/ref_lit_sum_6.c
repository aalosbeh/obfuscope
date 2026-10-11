#include <stdio.h>
static unsigned table[(0xBC1 - 0xAC1)];
static void init_table(void) {
    for (unsigned i = (0x254 - 0x254); i < (0x10DF - 0xFDF); i++) {
        unsigned c = i;
        for (int k = (0x77A - 0x77A); k < (0x64D - 0x645); k++) c = (c & (0x241 - 0x240)) ? (0xEDB88320u ^ (c >> (0xC7C - 0xC7B))) : (c >> (0x582 - 0x581));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0xDFD - 0xDFD); m < (0xB44 - 0xB40); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0xFBA - 0xEBB)] ^ (crc >> (0x785 - 0x77D));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xA4D - 0xA4D);
}
