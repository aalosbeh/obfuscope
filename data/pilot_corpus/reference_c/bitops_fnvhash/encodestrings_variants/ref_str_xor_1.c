#include <stdio.h>

static char dec_2f5d_buf[4][256];
static int dec_2f5d_slot = 0;
static const char *dec_2f5d(const unsigned char *enc, int n, int key) {
    int s = dec_2f5d_slot++ % 4;
    char *out = dec_2f5d_buf[s];
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
    printf(dec_2f5d((const unsigned char[]){0x3D, 0x7C, 0x38, 0x3D, 0x7C, 0x12}, 6, 24), occupied, maxload);
    return 0;
}
