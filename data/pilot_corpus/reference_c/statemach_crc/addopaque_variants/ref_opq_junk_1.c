#include <stdio.h>
static volatile int opq_52cb = 7;
static volatile int opq_52cb_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_52cb * opq_52cb + opq_52cb_b * opq_52cb_b) % 4) == 3)) {
            { int jv_d53f7 = opq_52cb ^ 0x4918;
                jv_d53f7 ^= (jv_d53f7 << 3) | 0x4612;
                jv_d53f7 = (jv_d53f7 * 0x2F) % 0x7FFFFFFF;
              (void)jv_d53f7; }
        }
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_52cb * opq_52cb) % 4) == 2)) {
            { int jv_7f48f = opq_52cb ^ 0xD2D7;
                jv_7f48f = (jv_7f48f * 0x3) % 0x7FFFFFFF;
              (void)jv_7f48f; }
        }
        table[i] = c;
        if ((((opq_52cb * opq_52cb) % 4) == 2)) {
            { int jv_6e1aa = opq_52cb ^ 0x451B;
                jv_6e1aa = (jv_6e1aa * 0x5) % 0x7FFFFFFF;
              (void)jv_6e1aa; }
        }
    }
}
int main(void) {
    if ((((opq_52cb * opq_52cb) % 4) == 2)) {
        { int jv_a0474 = opq_52cb ^ 0x1F5D;
            jv_a0474 = (jv_a0474 * 0x19) % 0x7FFFFFFF;
            jv_a0474 += (jv_a0474 >> 2) + 0x35;
          (void)jv_a0474; }
    }
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_52cb * opq_52cb + opq_52cb_b * opq_52cb_b) % 4) == 3)) {
        { int jv_a7075 = opq_52cb ^ 0x9D27;
            jv_a7075 ^= (jv_a7075 << 3) | 0xD055;
            jv_a7075 = (jv_a7075 * 0x2C) % 0x7FFFFFFF;
          (void)jv_a7075; }
    }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_52cb * opq_52cb + opq_52cb_b * opq_52cb_b) % 4) == 3)) {
            { int jv_9c5ae = opq_52cb ^ 0x5B39;
                jv_9c5ae ^= (jv_9c5ae << 3) | 0xF38F;
              (void)jv_9c5ae; }
        }
    }
    printf("\n");
    return 0;
}
