#include <stdio.h>
static volatile int opq_1198 = 7;
static volatile int opq_1198_b = 3;

static unsigned table[256];
static void init_table(void) {
    if (((opq_1198 * opq_1198 - opq_1198) % 2 == 0)) { opq_1198_b ^= 0; }
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        if ((((opq_1198 * opq_1198 + opq_1198_b * opq_1198_b) % 4) == 3)) {
            { int jv_ca1ba = opq_1198 ^ 0xD6E8;
                jv_ca1ba += (jv_ca1ba >> 2) + 0x2A;
                jv_ca1ba = (jv_ca1ba * 0x13) % 0x7FFFFFFF;
              (void)jv_ca1ba; }
        }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_1198 * (opq_1198 + 1)) % 2) == 0)) { opq_1198_b ^= 0; }
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        if (((opq_1198 * opq_1198 - opq_1198) % 2 == 0)) { opq_1198_b ^= 0; }
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_1198 * (opq_1198 + 1)) % 2) == 0)) { opq_1198_b ^= 0; }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if (((opq_1198 * opq_1198 - opq_1198) % 2 == 0)) { opq_1198_b ^= 0; }
    }
    printf("\n");
    return 0;
}
