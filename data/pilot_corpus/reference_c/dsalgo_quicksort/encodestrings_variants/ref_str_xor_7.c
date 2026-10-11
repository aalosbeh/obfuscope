#include <stdio.h>

static char dec_9b7b_buf[4][256];
static int dec_9b7b_slot = 0;
static const char *dec_9b7b(const unsigned char *enc, int n, int key) {
    int s = dec_9b7b_slot++ % 4;
    char *out = dec_9b7b_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - 1);
    qs(a, i + 1, hi);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long sum = 0;
    for (int i = 0; i < 32; i++) sum += (long)a[i] * i;
    printf(dec_9b7b((const unsigned char[]){0x7F, 0x36, 0x3E, 0x50}, 4, 90), sum);
    return 0;
}
