#include <stdio.h>

static char dec_b7c3_buf[4][256];
static int dec_b7c3_slot = 0;
static const char *dec_b7c3(const unsigned char *enc, int n, int key) {
    int s = dec_b7c3_slot++ % 4;
    char *out = dec_b7c3_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf(dec_b7c3((const unsigned char[]){0x36, 0x84, 0x31, 0x36, 0x7D, 0x75, 0x1B}, 7, 17), buf, acc);
    return 0;
}
