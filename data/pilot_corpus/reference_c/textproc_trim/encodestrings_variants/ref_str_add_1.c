#include <stdio.h>
#include <string.h>

static char dec_944f_buf[4][256];
static int dec_944f_slot = 0;
static const char *dec_944f(const unsigned char *enc, int n, int key) {
    int s = dec_944f_slot++ % 4;
    char *out = dec_944f_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf(dec_944f((const unsigned char[]){0xFE, 0xC8, 0x16, 0x00, 0xFE, 0xC8, 0x16, 0x00, 0xC3, 0xC8, 0x1D, 0x18, 0xAD}, 13, 163), a, b, strlen(a) + strlen(b));
    return 0;
}
