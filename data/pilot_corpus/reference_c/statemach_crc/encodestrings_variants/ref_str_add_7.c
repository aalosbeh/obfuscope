#include <stdio.h>

static char dec_e5ee_buf[4][256];
static int dec_e5ee_slot = 0;
static const char *dec_e5ee(const unsigned char *enc, int n, int key) {
    int s = dec_e5ee_slot++ % 4;
    char *out = dec_e5ee_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static unsigned table[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & 0xFF] ^ (crc >> 8);
        printf(dec_e5ee((const unsigned char[]){0xE5, 0xF0, 0xF8, 0x38, 0xE0}, 5, 192), crc ^ 0xFFFFFFFFu);
    }
    printf(dec_e5ee((const unsigned char[]){0xCA}, 1, 192));
    return 0;
}
