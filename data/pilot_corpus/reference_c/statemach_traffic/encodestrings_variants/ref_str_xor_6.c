#include <stdio.h>

static char dec_7269_buf[4][256];
static int dec_7269_slot = 0;
static const char *dec_7269(const unsigned char *enc, int n, int key) {
    int s = dec_7269_slot++ % 4;
    char *out = dec_7269_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf(dec_7269((const unsigned char[]){0x40, 0x01, 0x45, 0x40, 0x01, 0x45, 0x40, 0x01, 0x6F}, 9, 101), counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
