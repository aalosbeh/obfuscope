#include <stdio.h>

static char dec_c3f1_buf[4][256];
static int dec_c3f1_slot = 0;
static const char *dec_c3f1(const unsigned char *enc, int n, int key) {
    int s = dec_c3f1_slot++ % 4;
    char *out = dec_c3f1_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf(dec_c3f1((const unsigned char[]){0x96, 0xD7, 0x93, 0x96, 0xD7, 0x93, 0x96, 0xD7, 0xB9}, 9, 179), vends, credit, rejected);
    return 0;
}
