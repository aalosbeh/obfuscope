#include <stdio.h>

static char dec_5970_buf[4][256];
static int dec_5970_slot = 0;
static const char *dec_5970(const unsigned char *enc, int n, int key) {
    int s = dec_5970_slot++ % 4;
    char *out = dec_5970_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define N 8
int main(void) {
    int a[N][N], b[N][N], c[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { a[i][j] = (i + 1) * (j + 2) % 7; b[i][j] = (i * 3 + j) % 5; }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int k = 0; k < N; k++) s += a[i][k] * b[k][j];
            c[i][j] = s;
        }
    long trace = 0;
    for (int i = 0; i < N; i++) trace += c[i][i];
    printf(dec_5970((const unsigned char[]){0x89, 0xC0, 0xC8, 0xA6}, 4, 172), trace);
    return 0;
}
