#include <stdio.h>
#include <string.h>

static char dec_292e_buf[4][256];
static int dec_292e_slot = 0;
static const char *dec_292e(const unsigned char *enc, int n, int key) {
    int s = dec_292e_slot++ % 4;
    char *out = dec_292e_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
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
    printf(dec_292e((const unsigned char[]){0x59, 0x98, 0x54, 0x59, 0x98, 0x54, 0x59, 0x98, 0x3E}, 9, 52), nf, nonempty, total);
    return 0;
}
