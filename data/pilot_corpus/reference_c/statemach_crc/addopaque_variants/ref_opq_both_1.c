#include <stdio.h>
static volatile int opq_7ff5 = 7;
static volatile int opq_7ff5_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_7ff5 * opq_7ff5) % 4) == 2)) {
        { int jv_71b58 = opq_7ff5 ^ 0x1273;
            jv_71b58 ^= (jv_71b58 << 3) | 0x199E;
            jv_71b58 += (jv_71b58 >> 2) + 0x5D;
            jv_71b58 = (jv_71b58 * 0x22) % 0x7FFFFFFF;
          (void)jv_71b58; }
    }
    for (unsigned i = 0; i < 256; i++) {
        if (((opq_7ff5 * opq_7ff5 - opq_7ff5) % 2 == 0)) { opq_7ff5_b ^= 0; }
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
        if ((((opq_7ff5 * opq_7ff5) % 4) == 2)) {
            { int jv_145d2 = opq_7ff5 ^ 0x749D;
                jv_145d2 += (jv_145d2 >> 2) + 0xBE;
                jv_145d2 ^= (jv_145d2 << 3) | 0x9BA7;
              (void)jv_145d2; }
        }
    }
}
int main(void) {
    if ((((opq_7ff5 * opq_7ff5) % 4) == 2)) {
        { int jv_5a908 = opq_7ff5 ^ 0xF561;
            jv_5a908 += (jv_5a908 >> 2) + 0x3D;
            jv_5a908 ^= (jv_5a908 << 3) | 0x6AC2;
            jv_5a908 = (jv_5a908 * 0xB) % 0x7FFFFFFF;
          (void)jv_5a908; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_7ff5 * (opq_7ff5 + 1)) % 2) == 0)) { opq_7ff5_b ^= 0; }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    if ((((opq_7ff5 * opq_7ff5 + opq_7ff5) % 2) == 0)) { opq_7ff5_b ^= 0; }
    return 0;
}
