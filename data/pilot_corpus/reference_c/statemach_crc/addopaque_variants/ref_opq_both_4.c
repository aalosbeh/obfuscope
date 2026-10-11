#include <stdio.h>
static volatile int opq_3ac1 = 7;
static volatile int opq_3ac1_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
        if ((((opq_3ac1 * opq_3ac1) % 4) == 2)) {
            { int jv_4a5fa = opq_3ac1 ^ 0xB3C1;
                jv_4a5fa ^= (jv_4a5fa << 3) | 0xC5DB;
                jv_4a5fa += (jv_4a5fa >> 2) + 0xCB;
              (void)jv_4a5fa; }
        }
    }
}
int main(void) {
    if ((((opq_3ac1 * opq_3ac1 + opq_3ac1_b * opq_3ac1_b) % 4) == 3)) {
        { int jv_1e8d1 = opq_3ac1 ^ 0xC51;
            jv_1e8d1 = (jv_1e8d1 * 0x1E) % 0x7FFFFFFF;
            jv_1e8d1 ^= (jv_1e8d1 << 3) | 0x6B92;
            jv_1e8d1 += (jv_1e8d1 >> 2) + 0xAD;
          (void)jv_1e8d1; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if (((opq_3ac1 * opq_3ac1 - opq_3ac1) % 2 == 0)) { opq_3ac1_b ^= 0; }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        if ((((opq_3ac1 * opq_3ac1 + opq_3ac1) % 2) == 0)) { opq_3ac1_b ^= 0; }
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_3ac1 * (opq_3ac1 + 1)) % 2) == 0)) { opq_3ac1_b ^= 0; }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_3ac1 * opq_3ac1) % 4) == 2)) {
            { int jv_1ac1c = opq_3ac1 ^ 0x9CAB;
                jv_1ac1c += (jv_1ac1c >> 2) + 0xD1;
              (void)jv_1ac1c; }
        }
    }
    printf("\n");
    return 0;
}
