#include <stdio.h>

static char dec_f3d9_buf[4][256];
static int dec_f3d9_slot = 0;
static const char *dec_f3d9(const unsigned char *enc, int n, int key) {
    int s = dec_f3d9_slot++ % 4;
    char *out = dec_f3d9_buf[s];
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
    printf(dec_f3d9((const unsigned char[]){0x05, 0x44, 0x00, 0x05, 0x10, 0x18, 0x58, 0x2A}, 8, 32), count, fold);
    return 0;
}
