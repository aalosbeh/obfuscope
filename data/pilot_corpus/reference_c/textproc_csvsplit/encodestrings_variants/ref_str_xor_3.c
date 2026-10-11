#include <stdio.h>
#include <string.h>

static char dec_a08d_buf[4][256];
static int dec_a08d_slot = 0;
static const char *dec_a08d(const unsigned char *enc, int n, int key) {
    int s = dec_a08d_slot++ % 4;
    char *out = dec_a08d_buf[s];
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
    printf(dec_a08d((const unsigned char[]){0x79, 0x38, 0x7C, 0x79, 0x38, 0x7C, 0x79, 0x38, 0x56}, 9, 92), nf, nonempty, total);
    return 0;
}
