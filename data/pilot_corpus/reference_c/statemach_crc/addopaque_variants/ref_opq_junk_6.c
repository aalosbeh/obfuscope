#include <stdio.h>
static volatile int opq_667c = 7;
static volatile int opq_667c_b = 3;

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        if ((((opq_667c * opq_667c) % 4) == 2)) {
            { int jv_f93c7 = opq_667c ^ 0x79FE;
                jv_f93c7 ^= (jv_f93c7 << 3) | 0xB04B;
                jv_f93c7 = (jv_f93c7 * 0x23) % 0x7FFFFFFF;
                jv_f93c7 += (jv_f93c7 >> 2) + 0xD5;
              (void)jv_f93c7; }
        }
        unsigned c = i;
        if ((((opq_667c * opq_667c + opq_667c_b * opq_667c_b) % 4) == 3)) {
            { int jv_b7372 = opq_667c ^ 0x797E;
                jv_b7372 += (jv_b7372 >> 2) + 0x9A;
                jv_b7372 ^= (jv_b7372 << 3) | 0x6926;
                jv_b7372 = (jv_b7372 * 0x1A) % 0x7FFFFFFF;
              (void)jv_b7372; }
        }
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        if ((((opq_667c * opq_667c + opq_667c_b * opq_667c_b) % 4) == 3)) {
            { int jv_a835e = opq_667c ^ 0x5757;
                jv_a835e += (jv_a835e >> 2) + 0xA9;
              (void)jv_a835e; }
        }
        table[i] = c;
        if ((((opq_667c * opq_667c) % 4) == 2)) {
            { int jv_f3b91 = opq_667c ^ 0xFC34;
                jv_f3b91 ^= (jv_f3b91 << 3) | 0x79E;
                jv_f3b91 += (jv_f3b91 >> 2) + 0xEE;
              (void)jv_f3b91; }
        }
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    if ((((opq_667c * opq_667c + opq_667c_b * opq_667c_b) % 4) == 3)) {
        { int jv_4f486 = opq_667c ^ 0x3764;
            jv_4f486 ^= (jv_4f486 << 3) | 0xDDFF;
          (void)jv_4f486; }
    }
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf("%08x ", crc ^ 0xFFFFFFFFu);
        if ((((opq_667c * opq_667c) % 4) == 2)) {
            { int jv_90500 = opq_667c ^ 0x9BAE;
                jv_90500 += (jv_90500 >> 2) + 0x15;
              (void)jv_90500; }
        }
    }
    printf("\n");
    return 0;
}
