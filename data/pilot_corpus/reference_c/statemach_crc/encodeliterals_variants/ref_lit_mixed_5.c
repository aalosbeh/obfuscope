#include <stdio.h>
static unsigned table[(0x8FE - 0x7FE)];
static void init_table(void) {
    for (unsigned i = (0xAA1 - 0xAA1); i < (0xC3D - 0xB3D); i++) {
        unsigned c = i;
        for (int k = (0x6F6988C2 ^ 0x6F6988C2); k < (0xDF1 - 0xDE9); k++) c = (c & (0xE7 - 0xE6)) ? (0xEDB88320u ^ (c >> (0x30D - 0x30C))) : (c >> (0xF6F - 0xF6E));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x1A1 - 0x1A1); m < (0x92B - 0x927); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x7FF697FD ^ 0x7FF69702)] ^ (crc >> (0x287 - 0x27F));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x4FCADE97 ^ 0x4FCADE97);
}
