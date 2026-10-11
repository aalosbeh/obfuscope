#include <stdio.h>
static volatile int opq_ec48 = 7;
static volatile int opq_ec48_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_ec48 * opq_ec48 + opq_ec48_b * opq_ec48_b) % 4) == 3)) {
        { int jv_3c55f = opq_ec48 ^ 0xCEE4;
            jv_3c55f = (jv_3c55f * 0x21) % 0x7FFFFFFF;
          (void)jv_3c55f; }
    }
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_ec48 * opq_ec48 + opq_ec48_b * opq_ec48_b) % 4) == 3)) {
            { int jv_3a7d7 = opq_ec48 ^ 0x8E94;
                jv_3a7d7 = (jv_3a7d7 * 0x30) % 0x7FFFFFFF;
                jv_3a7d7 += (jv_3a7d7 >> 2) + 0x3D;
                jv_3a7d7 ^= (jv_3a7d7 << 3) | 0xEC4C;
              (void)jv_3a7d7; }
        }
        table[i] = c;
    }
}
int main(void) {
    if ((((opq_ec48 * opq_ec48 + opq_ec48_b * opq_ec48_b) % 4) == 3)) {
        { int jv_33b24 = opq_ec48 ^ 0xD78E;
            jv_33b24 ^= (jv_33b24 << 3) | 0xF5E0;
          (void)jv_33b24; }
    }
    init_table();
    if ((((opq_ec48 * opq_ec48) % 4) == 2)) {
        { int jv_7707b = opq_ec48 ^ 0x4625;
            jv_7707b = (jv_7707b * 0x3A) % 0x7FFFFFFF;
            jv_7707b += (jv_7707b >> 2) + 0xB9;
          (void)jv_7707b; }
    }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_ec48 * opq_ec48 + opq_ec48_b * opq_ec48_b) % 4) == 3)) {
        { int jv_46e89 = opq_ec48 ^ 0x9423;
            jv_46e89 += (jv_46e89 >> 2) + 0x89;
          (void)jv_46e89; }
    }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    if ((((opq_ec48 * opq_ec48) % 4) == 2)) {
        { int jv_e6d04 = opq_ec48 ^ 0xC1D1;
            jv_e6d04 ^= (jv_e6d04 << 3) | 0x44EB;
          (void)jv_e6d04; }
    }
    return 0;
}
