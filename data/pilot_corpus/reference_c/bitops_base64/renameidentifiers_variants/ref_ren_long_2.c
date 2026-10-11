#include <stdio.h>
static const char yihqylnzmijfzvt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char kxaavhuxxvtpud[] = "Obfuscation provenance";
    char hrgpzhfqgjsjtwmgslsu[64];
    int n = (int)sizeof(kxaavhuxxvtpud) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)kxaavhuxxvtpud[i] << 16;
        int xsxvxuufylimozwurbqx = n - i;
        if (xsxvxuufylimozwurbqx > 1) v |= (unsigned)kxaavhuxxvtpud[i+1] << 8;
        if (xsxvxuufylimozwurbqx > 2) v |= kxaavhuxxvtpud[i+2];
        hrgpzhfqgjsjtwmgslsu[o++] = yihqylnzmijfzvt[(v >> 18) & 63];
        hrgpzhfqgjsjtwmgslsu[o++] = yihqylnzmijfzvt[(v >> 12) & 63];
        hrgpzhfqgjsjtwmgslsu[o++] = (xsxvxuufylimozwurbqx > 1) ? yihqylnzmijfzvt[(v >> 6) & 63] : '=';
        hrgpzhfqgjsjtwmgslsu[o++] = (xsxvxuufylimozwurbqx > 2) ? yihqylnzmijfzvt[v & 63] : '=';
    }
    hrgpzhfqgjsjtwmgslsu[o] = '\0';
    printf("%s %d\n", hrgpzhfqgjsjtwmgslsu, o);
    return 0;
}
