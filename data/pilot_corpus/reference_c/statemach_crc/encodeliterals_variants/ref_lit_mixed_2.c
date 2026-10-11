#include <stdio.h>
static unsigned table[(0x940 - 0x840)];
static void init_table(void) {
    for (unsigned i = (0x6C9BAD27 ^ 0x6C9BAD27); i < (0x2188E41B ^ 0x2188E51B); i++) {
        unsigned c = i;
        for (int k = (0x3DE6D270 ^ 0x3DE6D270); k < (0x4A0B6E33 ^ 0x4A0B6E3B); k++) c = (c & (0x5D3ECA10 ^ 0x5D3ECA11)) ? (0xEDB88320u ^ (c >> (0x32C - 0x32B))) : (c >> (0x77 - 0x76));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x527 - 0x527); m < (0x27FC65D1 ^ 0x27FC65D5); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x8F9 - 0x7FA)] ^ (crc >> (0x67BAB5E4 ^ 0x67BAB5EC));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xDEA - 0xDEA);
}
