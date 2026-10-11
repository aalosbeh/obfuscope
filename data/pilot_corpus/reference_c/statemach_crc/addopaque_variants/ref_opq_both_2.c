#include <stdio.h>
static volatile int opq_75df = 7;
static volatile int opq_75df_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_75df * opq_75df) % 4) == 2)) {
        { int jv_6588b = opq_75df ^ 0x23CC;
            jv_6588b = (jv_6588b * 0x17) % 0x7FFFFFFF;
            jv_6588b ^= (jv_6588b << 3) | 0x78D8;
          (void)jv_6588b; }
    }
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_75df * opq_75df + opq_75df_b * opq_75df_b) % 4) == 3)) {
            { int jv_11775 = opq_75df ^ 0x37EC;
                jv_11775 ^= (jv_11775 << 3) | 0xCB69;
              (void)jv_11775; }
        }
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if (((opq_75df * opq_75df - opq_75df) % 2 == 0)) { opq_75df_b ^= 0; }
        table[i] = c;
    }
}
int main(void) {
    if ((((opq_75df * opq_75df) % 4) == 2)) {
        { int jv_70644 = opq_75df ^ 0x2BA9;
            jv_70644 ^= (jv_70644 << 3) | 0x626C;
            jv_70644 += (jv_70644 >> 2) + 0xDF;
          (void)jv_70644; }
    }
    init_table();
    if ((((opq_75df * opq_75df + opq_75df_b * opq_75df_b) % 4) == 3)) {
        { int jv_ab80b = opq_75df ^ 0xFA34;
            jv_ab80b += (jv_ab80b >> 2) + 0xC3;
            jv_ab80b ^= (jv_ab80b << 3) | 0x54BB;
          (void)jv_ab80b; }
    }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        if ((((opq_75df * opq_75df + opq_75df) % 2) == 0)) { opq_75df_b ^= 0; }
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
