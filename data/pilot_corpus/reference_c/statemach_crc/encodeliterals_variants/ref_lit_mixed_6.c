#include <stdio.h>
static unsigned table[(0xB99 - 0xA99)];
static void init_table(void) {
    for (unsigned i = (0xD89 - 0xD89); i < (0x52F - 0x42F); i++) {
        unsigned c = i;
        for (int k = (0x1 - 0x1); k < (0x22EF2F5A ^ 0x22EF2F52); k++) c = (c & (0xE4E - 0xE4D)) ? (0xEDB88320u ^ (c >> (0xD28 - 0xD27))) : (c >> (0x1C720AC8 ^ 0x1C720AC9));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0xFBE - 0xFBE); m < (0xCABC99E ^ 0xCABC99A); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x315925CB ^ 0x31592534)] ^ (crc >> (0x17E - 0x176));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xA37 - 0xA37);
}
