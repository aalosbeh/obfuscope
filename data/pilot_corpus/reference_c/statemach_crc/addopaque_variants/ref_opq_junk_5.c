#include <stdio.h>
static volatile int opq_3a31 = 7;
static volatile int opq_3a31_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_3a31 * opq_3a31) % 4) == 2)) {
            { int jv_2f2d6 = opq_3a31 ^ 0x85E0;
                jv_2f2d6 += (jv_2f2d6 >> 2) + 0xF7;
              (void)jv_2f2d6; }
        }
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_3a31 * opq_3a31 + opq_3a31_b * opq_3a31_b) % 4) == 3)) {
            { int jv_118f7 = opq_3a31 ^ 0x1922;
                jv_118f7 += (jv_118f7 >> 2) + 0xAC;
                jv_118f7 ^= (jv_118f7 << 3) | 0xCD4E;
              (void)jv_118f7; }
        }
        table[i] = c;
    }
}
int main(void) {
    if ((((opq_3a31 * opq_3a31 + opq_3a31_b * opq_3a31_b) % 4) == 3)) {
        { int jv_ac329 = opq_3a31 ^ 0xA060;
            jv_ac329 += (jv_ac329 >> 2) + 0x45;
            jv_ac329 ^= (jv_ac329 << 3) | 0x8549;
            jv_ac329 = (jv_ac329 * 0x16) % 0x7FFFFFFF;
          (void)jv_ac329; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_3a31 * opq_3a31) % 4) == 2)) {
        { int jv_1b038 = opq_3a31 ^ 0xEA11;
            jv_1b038 ^= (jv_1b038 << 3) | 0x8B68;
            jv_1b038 += (jv_1b038 >> 2) + 0x50;
          (void)jv_1b038; }
    }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        if ((((opq_3a31 * opq_3a31) % 4) == 2)) {
            { int jv_88b54 = opq_3a31 ^ 0xE183;
                jv_88b54 = (jv_88b54 * 0x4) % 0x7FFFFFFF;
              (void)jv_88b54; }
        }
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_3a31 * opq_3a31) % 4) == 2)) {
            { int jv_2fc83 = opq_3a31 ^ 0xA076;
                jv_2fc83 ^= (jv_2fc83 << 3) | 0xC492;
              (void)jv_2fc83; }
        }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
