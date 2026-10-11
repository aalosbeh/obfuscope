#include <stdio.h>

static char dec_772c_buf[4][256];
static int dec_772c_slot = 0;
static const char *dec_772c(const unsigned char *enc, int n, int key) {
    int s = dec_772c_slot++ % 4;
    char *out = dec_772c_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned buckets[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        buckets[h % 16u]++;
    }
    int occupied = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (buckets[i]) occupied++; if ((int)buckets[i] > maxload) maxload = buckets[i]; }
    printf(dec_772c((const unsigned char[]){0x67, 0x26, 0x62, 0x67, 0x26, 0x48}, 6, 66), occupied, maxload);
    return 0;
}
