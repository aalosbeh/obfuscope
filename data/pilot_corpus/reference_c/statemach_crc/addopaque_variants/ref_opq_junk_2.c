#include <stdio.h>
static volatile int opq_7c14 = 7;
static volatile int opq_7c14_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        if ((((opq_7c14 * opq_7c14 + opq_7c14_b * opq_7c14_b) % 4) == 3)) {
            { int jv_9c5a1 = opq_7c14 ^ 0x9E84;
                jv_9c5a1 ^= (jv_9c5a1 << 3) | 0xD1DA;
                jv_9c5a1 = (jv_9c5a1 * 0x8) % 0x7FFFFFFF;
              (void)jv_9c5a1; }
        }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
    }
}
int main(void) {
    if ((((opq_7c14 * opq_7c14 + opq_7c14_b * opq_7c14_b) % 4) == 3)) {
        { int jv_c240a = opq_7c14 ^ 0xC6DC;
            jv_c240a = (jv_c240a * 0x4) % 0x7FFFFFFF;
            jv_c240a += (jv_c240a >> 2) + 0xB0;
            jv_c240a ^= (jv_c240a << 3) | 0xA084;
          (void)jv_c240a; }
    }
    init_table();
    if ((((opq_7c14 * opq_7c14 + opq_7c14_b * opq_7c14_b) % 4) == 3)) {
        { int jv_a963c = opq_7c14 ^ 0xFAE0;
            jv_a963c += (jv_a963c >> 2) + 0xD5;
            jv_a963c = (jv_a963c * 0x10) % 0x7FFFFFFF;
          (void)jv_a963c; }
    }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_7c14 * opq_7c14 + opq_7c14_b * opq_7c14_b) % 4) == 3)) {
        { int jv_517ce = opq_7c14 ^ 0xE993;
            jv_517ce = (jv_517ce * 0x5) % 0x7FFFFFFF;
            jv_517ce += (jv_517ce >> 2) + 0xA7;
            jv_517ce ^= (jv_517ce << 3) | 0x1C1E;
          (void)jv_517ce; }
    }
    for (int m = 0; m < 4; m++) {
        if ((((opq_7c14 * opq_7c14 + opq_7c14_b * opq_7c14_b) % 4) == 3)) {
            { int jv_34383 = opq_7c14 ^ 0xF9A0;
                jv_34383 = (jv_34383 * 0x1F) % 0x7FFFFFFF;
              (void)jv_34383; }
        }
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_7c14 * opq_7c14) % 4) == 2)) {
            { int jv_ded84 = opq_7c14 ^ 0x4BA9;
                jv_ded84 = (jv_ded84 * 0x19) % 0x7FFFFFFF;
              (void)jv_ded84; }
        }
    }
    printf("\n");
    return 0;
}
