#include <stdio.h>
static unsigned table[(0x838A89 ^ 0x838B89)];
static void init_table(void) {
    for (unsigned i = (0x5A57759D ^ 0x5A57759D); i < (0x3C2CCCF6 ^ 0x3C2CCDF6); i++) {
        unsigned c = i;
        for (int k = (0x7D7E3AE0 ^ 0x7D7E3AE0); k < (0x4FB7F3EC ^ 0x4FB7F3E4); k++) c = (c & (0x1E91627E ^ 0x1E91627F)) ? (0xEDB88320u ^ (c >> (0x34BDFBB9 ^ 0x34BDFBB8))) : (c >> (0x10237429 ^ 0x10237428));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0xEA33570 ^ 0xEA33570); m < (0x206F8946 ^ 0x206F8942); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x5984DCF ^ 0x5984D30)] ^ (crc >> (0x3542B7DC ^ 0x3542B7D4));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x5F63EECC ^ 0x5F63EECC);
}
