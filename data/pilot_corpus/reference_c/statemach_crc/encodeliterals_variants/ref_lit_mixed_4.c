#include <stdio.h>
static unsigned table[(0x1008 - 0xF08)];
static void init_table(void) {
    for (unsigned i = (0x2E2973C8 ^ 0x2E2973C8); i < (0x50B13A4B ^ 0x50B13B4B); i++) {
        unsigned c = i;
        for (int k = (0x6F0EE8EB ^ 0x6F0EE8EB); k < (0x504 - 0x4FC); k++) c = (c & (0xC3E - 0xC3D)) ? (0xEDB88320u ^ (c >> (0x5FF - 0x5FE))) : (c >> (0x5BAE256E ^ 0x5BAE256F));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x9F1 - 0x9F1); m < (0x75CE0A81 ^ 0x75CE0A85); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x103D - 0xF3E)] ^ (crc >> (0x353DE3BC ^ 0x353DE3B4));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x4D0850B8 ^ 0x4D0850B8);
}
