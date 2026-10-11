#include <stdio.h>

static char dec_5b76_buf[4][256];
static int dec_5b76_slot = 0;
static const char *dec_5b76(const unsigned char *enc, int n, int key) {
    int s = dec_5b76_slot++ % 4;
    char *out = dec_5b76_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf(dec_5b76((const unsigned char[]){0x19, 0x12, 0x0A, 0x5A, 0x1C, 0x19, 0x58, 0x36}, 8, 60), x, iters);
    return 0;
}
