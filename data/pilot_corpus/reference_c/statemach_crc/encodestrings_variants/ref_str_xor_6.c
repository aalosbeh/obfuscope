#include <stdio.h>

static char dec_7587_buf[4][256];
static int dec_7587_slot = 0;
static const char *dec_7587(const unsigned char *enc, int n, int key) {
    int s = dec_7587_slot++ % 4;
    char *out = dec_7587_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
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
        printf(dec_7587((const unsigned char[]){0xBD, 0xA8, 0xA0, 0xE0, 0xB8}, 5, 152), crc ^ 0xFFFFFFFFu);
    }
    printf(dec_7587((const unsigned char[]){0x92}, 1, 152));
    return 0;
}
