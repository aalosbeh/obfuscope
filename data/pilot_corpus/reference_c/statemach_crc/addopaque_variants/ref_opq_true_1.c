#include <stdio.h>
static volatile int opq_7bfe = 7;
static volatile int opq_7bfe_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_7bfe * opq_7bfe + opq_7bfe) % 2) == 0)) { opq_7bfe_b ^= 0; }
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_7bfe * (opq_7bfe + 1)) % 2) == 0)) { opq_7bfe_b ^= 0; }
        unsigned c = i;
        if ((((opq_7bfe * (opq_7bfe + 1)) % 2) == 0)) { opq_7bfe_b ^= 0; }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
    }
}
int main(void) {
    init_table();
    if ((((opq_7bfe * opq_7bfe + opq_7bfe) % 2) == 0)) { opq_7bfe_b ^= 0; }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        if ((((opq_7bfe * opq_7bfe + opq_7bfe) % 2) == 0)) { opq_7bfe_b ^= 0; }
        unsigned crc = 0xFFFFFFFFu;
        if (((opq_7bfe * opq_7bfe - opq_7bfe) % 2 == 0)) { opq_7bfe_b ^= 0; }
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
