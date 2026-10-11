#include <stdio.h>
#include <string.h>

static char dec_3243_buf[4][256];
static int dec_3243_slot = 0;
static const char *dec_3243(const unsigned char *enc, int n, int key) {
    int s = dec_3243_slot++ % 4;
    char *out = dec_3243_buf[s];
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
    printf(dec_3243((const unsigned char[]){0xCD, 0x97, 0xE5, 0xCF, 0xCD, 0x97, 0xE5, 0xCF, 0x92, 0x97, 0xEC, 0xE7, 0x7C}, 13, 114), a, b, strlen(a) + strlen(b));
    return 0;
}
