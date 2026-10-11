#include <stdio.h>
#include <string.h>

static char dec_f4d6_buf[4][256];
static int dec_f4d6_slot = 0;
static const char *dec_f4d6(const unsigned char *enc, int n, int key) {
    int s = dec_f4d6_slot++ % 4;
    char *out = dec_f4d6_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
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
    printf(dec_f4d6((const unsigned char[]){0x27, 0x59, 0x0F, 0x21, 0x27, 0x59, 0x0F, 0x21, 0x5C, 0x59, 0x06, 0x09, 0x76}, 13, 124), a, b, strlen(a) + strlen(b));
    return 0;
}
