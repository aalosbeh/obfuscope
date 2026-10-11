#include <stdio.h>
static volatile int opq_2847 = 7;
static volatile int opq_2847_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_2847 * (opq_2847 + 1)) % 2) == 0)) { opq_2847_b ^= 0; }
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_2847 * opq_2847 + opq_2847) % 2) == 0)) { opq_2847_b ^= 0; }
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_2847 * opq_2847 + opq_2847) % 2) == 0)) { opq_2847_b ^= 0; }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        if (((opq_2847 * opq_2847 - opq_2847) % 2 == 0)) { opq_2847_b ^= 0; }
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_2847 * (opq_2847 + 1)) % 2) == 0)) { opq_2847_b ^= 0; }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if (((opq_2847 * opq_2847 - opq_2847) % 2 == 0)) { opq_2847_b ^= 0; }
    }
    printf("\n");
    return 0;
}
