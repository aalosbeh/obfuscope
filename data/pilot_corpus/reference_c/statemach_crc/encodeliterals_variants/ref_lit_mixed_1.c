#include <stdio.h>
static unsigned table[(0x41F082CE ^ 0x41F083CE)];
static void init_table(void) {
    for (unsigned i = (0x48289FBA ^ 0x48289FBA); i < (0xFCA - 0xECA); i++) {
        unsigned c = i;
        for (int k = (0xDD2 - 0xDD2); k < (0xA18 - 0xA10); k++) c = (c & (0xDF6 - 0xDF5)) ? (0xEDB88320u ^ (c >> (0x510 - 0x50F))) : (c >> (0xA86 - 0xA85));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x469 - 0x469); m < (0x68F51417 ^ 0x68F51413); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x31ECEB59 ^ 0x31ECEBA6)] ^ (crc >> (0x401 - 0x3F9));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0xCA0 - 0xCA0);
}
