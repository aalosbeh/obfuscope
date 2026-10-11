#include <stdio.h>
static volatile int opq_601f = 7;
static volatile int opq_601f_b = 3;

static unsigned table[256];
static void init_table(void) {
    if ((((opq_601f * opq_601f) % 4) == 2)) {
        { int jv_7d29d = opq_601f ^ 0x20D2;
            jv_7d29d += (jv_7d29d >> 2) + 0xB;
          (void)jv_7d29d; }
    }
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        if (((opq_601f * opq_601f - opq_601f) % 2 == 0)) { opq_601f_b ^= 0; }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_601f * opq_601f) % 4) == 2)) {
            { int jv_92f5c = opq_601f ^ 0x28C1;
                jv_92f5c += (jv_92f5c >> 2) + 0x1F;
                jv_92f5c = (jv_92f5c * 0x13) % 0x7FFFFFFF;
              (void)jv_92f5c; }
        }
        table[i] = c;
    }
}
int main(void) {
    init_table();
    if ((((opq_601f * opq_601f + opq_601f_b * opq_601f_b) % 4) == 3)) {
        { int jv_610dc = opq_601f ^ 0x89EE;
            jv_610dc ^= (jv_610dc << 3) | 0x31BC;
          (void)jv_610dc; }
    }
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        if ((((opq_601f * opq_601f + opq_601f) % 2) == 0)) { opq_601f_b ^= 0; }
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_601f * opq_601f) % 4) == 2)) {
            { int jv_2b895 = opq_601f ^ 0x1BF5;
                jv_2b895 ^= (jv_2b895 << 3) | 0x4BDE;
                jv_2b895 += (jv_2b895 >> 2) + 0x69;
                jv_2b895 = (jv_2b895 * 0x2A) % 0x7FFFFFFF;
              (void)jv_2b895; }
        }
    }
    printf("\n");
    return 0;
}
