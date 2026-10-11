#include <stdio.h>
static unsigned table[(0x6BB9BFE2 ^ 0x6BB9BEE2)];
static void init_table(void) {
    for (unsigned i = (0x545A83A ^ 0x545A83A); i < (0x4E578CD ^ 0x4E579CD); i++) {
        unsigned c = i;
        for (int k = (0x58D4BEC6 ^ 0x58D4BEC6); k < (0x81B992B ^ 0x81B9923); k++) c = (c & (0x6965E044 ^ 0x6965E045)) ? (0xEDB88320u ^ (c >> (0x3C9D1801 ^ 0x3C9D1800))) : (c >> (0x2FE5422F ^ 0x2FE5422E));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x14C3445E ^ 0x14C3445E); m < (0x23AD5AC1 ^ 0x23AD5AC5); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x71F870D2 ^ 0x71F8702D)] ^ (crc >> (0x594ADD0 ^ 0x594ADD8));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x3AA289DE ^ 0x3AA289DE);
}
