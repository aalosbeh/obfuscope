#include <stdio.h>

static char dec_62f7_buf[4][256];
static int dec_62f7_slot = 0;
static const char *dec_62f7(const unsigned char *enc, int n, int key) {
    int s = dec_62f7_slot++ % 4;
    char *out = dec_62f7_buf[s];
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
    printf(dec_62f7((const unsigned char[]){0x09, 0x48, 0xEE}, 3, 228), found);
    return 0;
}
