#include <stdio.h>
static volatile int opq_1073 = 7;
static volatile int opq_1073_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_1073 * opq_1073) % 4) == 2)) {
        { int jv_a3f42 = opq_1073 ^ 0x2C74;
            jv_a3f42 ^= (jv_a3f42 << 3) | 0xB092;
          (void)jv_a3f42; }
    }
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        if ((((opq_1073 * opq_1073) % 4) == 2)) {
            { int jv_ea061 = opq_1073 ^ 0xC9C4;
                jv_ea061 ^= (jv_ea061 << 3) | 0x7DE9;
              (void)jv_ea061; }
        }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_1073 * opq_1073) % 4) == 2)) {
        { int jv_8d5be = opq_1073 ^ 0xF2A7;
            jv_8d5be = (jv_8d5be * 0x2D) % 0x7FFFFFFF;
            jv_8d5be ^= (jv_8d5be << 3) | 0x9E4A;
          (void)jv_8d5be; }
    }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_1073 * opq_1073 + opq_1073_b * opq_1073_b) % 4) == 3)) {
            { int jv_aef88 = opq_1073 ^ 0x3A5A;
                jv_aef88 += (jv_aef88 >> 2) + 0x2C;
                jv_aef88 ^= (jv_aef88 << 3) | 0xD759;
              (void)jv_aef88; }
        }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_1073 * opq_1073) % 4) == 2)) {
            { int jv_a5e8e = opq_1073 ^ 0x2C92;
                jv_a5e8e = (jv_a5e8e * 0x6) % 0x7FFFFFFF;
                jv_a5e8e += (jv_a5e8e >> 2) + 0xAD;
                jv_a5e8e ^= (jv_a5e8e << 3) | 0x61BA;
              (void)jv_a5e8e; }
        }
    }
    printf("\n");
    if ((((opq_1073 * opq_1073 + opq_1073_b * opq_1073_b) % 4) == 3)) {
        { int jv_aac08 = opq_1073 ^ 0x8741;
            jv_aac08 = (jv_aac08 * 0x18) % 0x7FFFFFFF;
          (void)jv_aac08; }
    }
    return 0;
}
