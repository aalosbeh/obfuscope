#include <stdio.h>

static char dec_7c23_buf[4][256];
static int dec_7c23_slot = 0;
static const char *dec_7c23(const unsigned char *enc, int n, int key) {
    int s = dec_7c23_slot++ % 4;
    char *out = dec_7c23_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static int bsearch_idx(const int *a, int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int found = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) found++;
    printf(dec_7c23((const unsigned char[]){0xA9, 0xE8, 0x8E}, 3, 132), found);
    return 0;
}
