#include <stdio.h>

static char dec_a018_buf[4][256];
static int dec_a018_slot = 0;
static const char *dec_a018(const unsigned char *enc, int n, int key) {
    int s = dec_a018_slot++ % 4;
    char *out = dec_a018_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
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
    printf(dec_a018((const unsigned char[]){0x9C, 0xDB, 0x97, 0x9C, 0xDB, 0x81}, 6, 119), occupied, maxload);
    return 0;
}
