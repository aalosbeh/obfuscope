#include <stdio.h>
static unsigned table[(0x771B8AC ^ 0x771B9AC)];
static void init_table(void) {
    for (unsigned i = (0xD50 - 0xD50); i < (0x997 - 0x897); i++) {
        unsigned c = i;
        for (int k = (0x4EA - 0x4EA); k < (0xCC44C85 ^ 0xCC44C8D); k++) c = (c & (0x1F8 - 0x1F7)) ? (0xEDB88320u ^ (c >> (0xA09 - 0xA08))) : (c >> (0x5FC7ED83 ^ 0x5FC7ED82));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x3C43413 ^ 0x3C43413); m < (0x22D3C025 ^ 0x22D3C021); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0xACC - 0x9CD)] ^ (crc >> (0xF48201D ^ 0xF482015));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x487A4B05 ^ 0x487A4B05);
}
