#include <stdio.h>
static volatile int opq_45c5 = 7;
static volatile int opq_45c5_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_45c5 * opq_45c5 + opq_45c5_b * opq_45c5_b) % 4) == 3)) {
            { int jv_64f6a = opq_45c5 ^ 0x732A;
                jv_64f6a ^= (jv_64f6a << 3) | 0x713B;
              (void)jv_64f6a; }
        }
        table[i] = c;
    }
}
int main(void) {
    init_table();
    if ((((opq_45c5 * opq_45c5 + opq_45c5) % 2) == 0)) { opq_45c5_b ^= 0; }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if (((opq_45c5 * opq_45c5 - opq_45c5) % 2 == 0)) { opq_45c5_b ^= 0; }
    for (int m = 0; m < 4; m++) {
        if ((((opq_45c5 * opq_45c5 + opq_45c5) % 2) == 0)) { opq_45c5_b ^= 0; }
        unsigned crc = 0xFFFFFFFFu;
        if (((opq_45c5 * opq_45c5 - opq_45c5) % 2 == 0)) { opq_45c5_b ^= 0; }
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_45c5 * opq_45c5 + opq_45c5_b * opq_45c5_b) % 4) == 3)) {
            { int jv_eba81 = opq_45c5 ^ 0xB1F1;
                jv_eba81 ^= (jv_eba81 << 3) | 0xAF37;
                jv_eba81 = (jv_eba81 * 0xF) % 0x7FFFFFFF;
                jv_eba81 += (jv_eba81 >> 2) + 0x42;
              (void)jv_eba81; }
        }
    }
    printf("\n");
    return 0;
}
