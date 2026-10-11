#include <stdio.h>

static char dec_5353_buf[4][256];
static int dec_5353_slot = 0;
static const char *dec_5353(const unsigned char *enc, int n, int key) {
    int s = dec_5353_slot++ % 4;
    char *out = dec_5353_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(buf) - 1;
    for (int round = 0; round < 2; round++)
        for (int i = 0; i < n; i++) buf[i] ^= key[i % 4];
    long sum = 0;
    for (int i = 0; i < n; i++) sum += buf[i];
    printf(dec_5353((const unsigned char[]){0xB8, 0x06, 0xB3, 0xB8, 0xFF, 0xF7, 0x9D}, 7, 147), (char *)buf, sum);
    return 0;
}
