#include <stdio.h>
static unsigned table[(0x5B446258 ^ 0x5B446358)];
static void init_table(void) {
    for (unsigned i = (0x2D91BE67 ^ 0x2D91BE67); i < (0x6F8774E9 ^ 0x6F8775E9); i++) {
        unsigned c = i;
        for (int k = (0x7FE82ADF ^ 0x7FE82ADF); k < (0x7529CCF3 ^ 0x7529CCFB); k++) c = (c & (0x7CC49A97 ^ 0x7CC49A96)) ? (0xEDB88320u ^ (c >> (0x5BB47761 ^ 0x5BB47760))) : (c >> (0x6CAA1547 ^ 0x6CAA1546));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x65CD9874 ^ 0x65CD9874); m < (0x44AE13B4 ^ 0x44AE13B0); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x531689B9 ^ 0x53168946)] ^ (crc >> (0x2ADD0DC4 ^ 0x2ADD0DCC));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x5164F5C4 ^ 0x5164F5C4);
}
