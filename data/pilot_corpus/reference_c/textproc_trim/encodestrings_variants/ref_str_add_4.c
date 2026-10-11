#include <stdio.h>
#include <string.h>

static char dec_820c_buf[4][256];
static int dec_820c_slot = 0;
static const char *dec_820c(const unsigned char *enc, int n, int key) {
    int s = dec_820c_slot++ % 4;
    char *out = dec_820c_buf[s];
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
    printf(dec_820c((const unsigned char[]){0xD5, 0x9F, 0xED, 0xD7, 0xD5, 0x9F, 0xED, 0xD7, 0x9A, 0x9F, 0xF4, 0xEF, 0x84}, 13, 122), a, b, strlen(a) + strlen(b));
    return 0;
}
