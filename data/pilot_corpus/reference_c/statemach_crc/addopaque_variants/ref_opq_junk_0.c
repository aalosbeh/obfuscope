#include <stdio.h>
static volatile int opq_fcb2 = 7;
static volatile int opq_fcb2_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_fcb2 * opq_fcb2) % 4) == 2)) {
        { int jv_ba788 = opq_fcb2 ^ 0x8477;
            jv_ba788 = (jv_ba788 * 0x1F) % 0x7FFFFFFF;
          (void)jv_ba788; }
    }
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_fcb2 * opq_fcb2 + opq_fcb2_b * opq_fcb2_b) % 4) == 3)) {
            { int jv_edb53 = opq_fcb2 ^ 0x9BEB;
                jv_edb53 ^= (jv_edb53 << 3) | 0xE4D8;
                jv_edb53 = (jv_edb53 * 0x24) % 0x7FFFFFFF;
              (void)jv_edb53; }
        }
        table[i] = c;
        if ((((opq_fcb2 * opq_fcb2) % 4) == 2)) {
            { int jv_c2d83 = opq_fcb2 ^ 0xBDD0;
                jv_c2d83 += (jv_c2d83 >> 2) + 0x2F;
              (void)jv_c2d83; }
        }
    }
}
int main(void) {
    if ((((opq_fcb2 * opq_fcb2 + opq_fcb2_b * opq_fcb2_b) % 4) == 3)) {
        { int jv_6b80a = opq_fcb2 ^ 0x5E52;
            jv_6b80a = (jv_6b80a * 0x1F) % 0x7FFFFFFF;
            jv_6b80a ^= (jv_6b80a << 3) | 0xC481;
          (void)jv_6b80a; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_fcb2 * opq_fcb2 + opq_fcb2_b * opq_fcb2_b) % 4) == 3)) {
            { int jv_3f79f = opq_fcb2 ^ 0x666C;
                jv_3f79f = (jv_3f79f * 0xB) % 0x7FFFFFFF;
                jv_3f79f += (jv_3f79f >> 2) + 0x5E;
              (void)jv_3f79f; }
        }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_fcb2 * opq_fcb2 + opq_fcb2_b * opq_fcb2_b) % 4) == 3)) {
            { int jv_c2268 = opq_fcb2 ^ 0xAAB2;
                jv_c2268 = (jv_c2268 * 0x15) % 0x7FFFFFFF;
              (void)jv_c2268; }
        }
    }
    printf("\n");
    return 0;
}
