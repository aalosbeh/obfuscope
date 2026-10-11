#include <stdio.h>

static char dec_d2a2_buf[4][256];
static int dec_d2a2_slot = 0;
static const char *dec_d2a2(const unsigned char *enc, int n, int key) {
    int s = dec_d2a2_slot++ % 4;
    char *out = dec_d2a2_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf(dec_d2a2((const unsigned char[]){0x82, 0xC3, 0x87, 0x82, 0x97, 0x9F, 0xDF, 0xAD}, 8, 167), count, fold);
    return 0;
}
