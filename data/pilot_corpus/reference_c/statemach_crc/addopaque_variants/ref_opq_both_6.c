#include <stdio.h>
static volatile int opq_9ae1 = 7;
static volatile int opq_9ae1_b = 3;

static unsigned table[256];
static void init_table(void) {
    if (((opq_9ae1 * opq_9ae1 - opq_9ae1) % 2 == 0)) { opq_9ae1_b ^= 0; }
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        if ((((opq_9ae1 * (opq_9ae1 + 1)) % 2) == 0)) { opq_9ae1_b ^= 0; }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_9ae1 * opq_9ae1) % 4) == 2)) {
            { int jv_171cf = opq_9ae1 ^ 0x87EC;
                jv_171cf += (jv_171cf >> 2) + 0x11;
                jv_171cf ^= (jv_171cf << 3) | 0xE6B0;
              (void)jv_171cf; }
        }
        table[i] = c;
        if ((((opq_9ae1 * opq_9ae1 + opq_9ae1_b * opq_9ae1_b) % 4) == 3)) {
            { int jv_adf2f = opq_9ae1 ^ 0x3A4D;
                jv_adf2f = (jv_adf2f * 0x10) % 0x7FFFFFFF;
              (void)jv_adf2f; }
        }
    }
}
int main(void) {
    if ((((opq_9ae1 * opq_9ae1 + opq_9ae1_b * opq_9ae1_b) % 4) == 3)) {
        { int jv_6b304 = opq_9ae1 ^ 0xFB09;
            jv_6b304 += (jv_6b304 >> 2) + 0xF;
          (void)jv_6b304; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_9ae1 * opq_9ae1 + opq_9ae1_b * opq_9ae1_b) % 4) == 3)) {
            { int jv_d5f66 = opq_9ae1 ^ 0xEC0E;
                jv_d5f66 ^= (jv_d5f66 << 3) | 0x2EC7;
              (void)jv_d5f66; }
        }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
