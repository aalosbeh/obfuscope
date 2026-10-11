#include <stdio.h>

static char dec_a0c5_buf[4][256];
static int dec_a0c5_slot = 0;
static const char *dec_a0c5(const unsigned char *enc, int n, int key) {
    int s = dec_a0c5_slot++ % 4;
    char *out = dec_a0c5_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf(dec_a0c5((const unsigned char[]){0xDB, 0x1A, 0xD6, 0xDB, 0x1A, 0xC0}, 6, 182), used, depth(root));
    return 0;
}
