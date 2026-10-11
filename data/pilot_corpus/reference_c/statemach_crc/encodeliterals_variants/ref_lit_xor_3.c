#include <stdio.h>
static unsigned table[(0x3BC29B4F ^ 0x3BC29A4F)];
static void init_table(void) {
    for (unsigned i = (0x30163626 ^ 0x30163626); i < (0xDC9DF09 ^ 0xDC9DE09); i++) {
        unsigned c = i;
        for (int k = (0x1CA1B4E6 ^ 0x1CA1B4E6); k < (0x436B22A1 ^ 0x436B22A9); k++) c = (c & (0x26926B81 ^ 0x26926B80)) ? (0xEDB88320u ^ (c >> (0x3776408D ^ 0x3776408C))) : (c >> (0x4891E102 ^ 0x4891E103));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x50985490 ^ 0x50985490); m < (0x48259C96 ^ 0x48259C92); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x64DF8168 ^ 0x64DF8197)] ^ (crc >> (0xA748E7F ^ 0xA748E77));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x7E5D4D83 ^ 0x7E5D4D83);
}
