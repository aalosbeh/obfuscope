#include <stdio.h>
static volatile int opq_ecef = 7;
static volatile int opq_ecef_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_ecef * opq_ecef + opq_ecef_b * opq_ecef_b) % 4) == 3)) {
            { int jv_41d53 = opq_ecef ^ 0xB382;
                jv_41d53 += (jv_41d53 >> 2) + 0x35;
                jv_41d53 ^= (jv_41d53 << 3) | 0x68C0;
              (void)jv_41d53; }
        }
        unsigned c = i;
        if ((((opq_ecef * opq_ecef) % 4) == 2)) {
            { int jv_776e1 = opq_ecef ^ 0xF930;
                jv_776e1 ^= (jv_776e1 << 3) | 0xE0D6;
                jv_776e1 = (jv_776e1 * 0xE) % 0x7FFFFFFF;
                jv_776e1 += (jv_776e1 >> 2) + 0x72;
              (void)jv_776e1; }
        }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
        if ((((opq_ecef * opq_ecef + opq_ecef) % 2) == 0)) { opq_ecef_b ^= 0; }
    }
}
int main(void) {
    init_table();
    if ((((opq_ecef * opq_ecef) % 4) == 2)) {
        { int jv_32756 = opq_ecef ^ 0x53CF;
            jv_32756 += (jv_32756 >> 2) + 0xC5;
            jv_32756 ^= (jv_32756 << 3) | 0x8A0F;
            jv_32756 = (jv_32756 * 0x24) % 0x7FFFFFFF;
          (void)jv_32756; }
    }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        if ((((opq_ecef * (opq_ecef + 1)) % 2) == 0)) { opq_ecef_b ^= 0; }
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_ecef * opq_ecef) % 4) == 2)) {
            { int jv_7068c = opq_ecef ^ 0x587E;
                jv_7068c ^= (jv_7068c << 3) | 0xBD45;
              (void)jv_7068c; }
        }
    }
    printf("\n");
    return 0;
}
