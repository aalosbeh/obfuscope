#include <stdio.h>
static unsigned table[(0x4A3 - 0x3A3)];
static void init_table(void) {
    for (unsigned i = (0x8A9 - 0x8A9); i < (0x7373BDB9 ^ 0x7373BCB9); i++) {
        unsigned c = i;
        for (int k = (0x522 - 0x522); k < (0x297 - 0x28F); k++) c = (c & (0x6F710AB6 ^ 0x6F710AB7)) ? (0xEDB88320u ^ (c >> (0x7563C2D9 ^ 0x7563C2D8))) : (c >> (0x195 - 0x194));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x272 - 0x272); m < (0x1E7A8140 ^ 0x1E7A8144); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x2998973B ^ 0x299897C4)] ^ (crc >> (0x4337E446 ^ 0x4337E44E));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xCB8 - 0xCB8);
}
