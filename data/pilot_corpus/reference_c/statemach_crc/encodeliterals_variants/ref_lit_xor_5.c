#include <stdio.h>
static unsigned table[(0x1A9203DB ^ 0x1A9202DB)];
static void init_table(void) {
    for (unsigned i = (0x6CC78627 ^ 0x6CC78627); i < (0x7C1DCE1 ^ 0x7C1DDE1); i++) {
        unsigned c = i;
        for (int k = (0x15328279 ^ 0x15328279); k < (0x38BB7257 ^ 0x38BB725F); k++) c = (c & (0x6D2470DF ^ 0x6D2470DE)) ? (0xEDB88320u ^ (c >> (0x606836B4 ^ 0x606836B5))) : (c >> (0x257B017A ^ 0x257B017B));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x298A866A ^ 0x298A866A); m < (0x61730860 ^ 0x61730864); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x7EF2BF85 ^ 0x7EF2BF7A)] ^ (crc >> (0x332E37AB ^ 0x332E37A3));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x7158B20E ^ 0x7158B20E);
}
