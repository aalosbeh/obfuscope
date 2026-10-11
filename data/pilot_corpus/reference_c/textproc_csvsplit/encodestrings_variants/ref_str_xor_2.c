#include <stdio.h>
#include <string.h>

static char dec_995f_buf[4][256];
static int dec_995f_slot = 0;
static const char *dec_995f(const unsigned char *enc, int n, int key) {
    int s = dec_995f_slot++ % 4;
    char *out = dec_995f_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = 0;
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + 1;
            if (last) break;
        }
    }
    int nonempty = 0, total = 0;
    for (int i = 0; i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf(dec_995f((const unsigned char[]){0x8E, 0xCF, 0x8B, 0x8E, 0xCF, 0x8B, 0x8E, 0xCF, 0xA1}, 9, 171), nf, nonempty, total);
    return 0;
}
