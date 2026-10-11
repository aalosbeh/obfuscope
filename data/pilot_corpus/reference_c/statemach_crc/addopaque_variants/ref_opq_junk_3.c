#include <stdio.h>
static volatile int opq_b2a2 = 7;
static volatile int opq_b2a2_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_b2a2 * opq_b2a2) % 4) == 2)) {
        { int jv_6e846 = opq_b2a2 ^ 0x56B6;
            jv_6e846 += (jv_6e846 >> 2) + 0xE6;
            jv_6e846 = (jv_6e846 * 0x3B) % 0x7FFFFFFF;
          (void)jv_6e846; }
    }
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_b2a2 * opq_b2a2 + opq_b2a2_b * opq_b2a2_b) % 4) == 3)) {
            { int jv_49cf4 = opq_b2a2 ^ 0xF4FC;
                jv_49cf4 = (jv_49cf4 * 0x15) % 0x7FFFFFFF;
                jv_49cf4 ^= (jv_49cf4 << 3) | 0x84CB;
                jv_49cf4 += (jv_49cf4 >> 2) + 0xA1;
              (void)jv_49cf4; }
        }
        unsigned c = i;
        if ((((opq_b2a2 * opq_b2a2) % 4) == 2)) {
            { int jv_2c296 = opq_b2a2 ^ 0x5DD0;
                jv_2c296 ^= (jv_2c296 << 3) | 0xF587;
                jv_2c296 = (jv_2c296 * 0x13) % 0x7FFFFFFF;
                jv_2c296 += (jv_2c296 >> 2) + 0x78;
              (void)jv_2c296; }
        }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
        if ((((opq_b2a2 * opq_b2a2 + opq_b2a2_b * opq_b2a2_b) % 4) == 3)) {
            { int jv_6c42d = opq_b2a2 ^ 0xF2BE;
                jv_6c42d ^= (jv_6c42d << 3) | 0x46B6;
              (void)jv_6c42d; }
        }
    }
}
int main(void) {
    if ((((opq_b2a2 * opq_b2a2) % 4) == 2)) {
        { int jv_aa634 = opq_b2a2 ^ 0xD017;
            jv_aa634 ^= (jv_aa634 << 3) | 0xDF74;
          (void)jv_aa634; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_b2a2 * opq_b2a2) % 4) == 2)) {
        { int jv_5b62f = opq_b2a2 ^ 0x6F27;
            jv_5b62f = (jv_5b62f * 0x31) % 0x7FFFFFFF;
          (void)jv_5b62f; }
    }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
