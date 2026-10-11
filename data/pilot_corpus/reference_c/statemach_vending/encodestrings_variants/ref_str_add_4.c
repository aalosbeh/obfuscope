#include <stdio.h>

static char dec_904d_buf[4][256];
static int dec_904d_slot = 0;
static const char *dec_904d(const unsigned char *enc, int n, int key) {
    int s = dec_904d_slot++ % 4;
    char *out = dec_904d_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
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
    printf(dec_904d((const unsigned char[]){0x7B, 0xBA, 0x76, 0x7B, 0xBA, 0x76, 0x7B, 0xBA, 0x60}, 9, 86), vends, credit, rejected);
    return 0;
}
