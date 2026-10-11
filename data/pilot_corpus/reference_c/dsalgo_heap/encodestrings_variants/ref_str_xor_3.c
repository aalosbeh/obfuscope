#include <stdio.h>

static char dec_9d3f_buf[4][256];
static int dec_9d3f_slot = 0;
static const char *dec_9d3f(const unsigned char *enc, int n, int key) {
    int s = dec_9d3f_slot++ % 4;
    char *out = dec_9d3f_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf(dec_9d3f((const unsigned char[]){0x6B, 0x22, 0x2A, 0x44}, 4, 78), acc & 0xffffff);
    return 0;
}
