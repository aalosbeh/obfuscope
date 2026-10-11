#include <stdio.h>
static const char pjymcsaqqbobtebnfos[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char akbojvgksdsgzhqk[] = "Obfuscation provenance";
    char thuzrwfupcexpfahqfbkrt[64];
    int n = (int)sizeof(akbojvgksdsgzhqk) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)akbojvgksdsgzhqk[i] << 16;
        int vuupfsmoybrktlyccc = n - i;
        if (vuupfsmoybrktlyccc > 1) v |= (unsigned)akbojvgksdsgzhqk[i+1] << 8;
        if (vuupfsmoybrktlyccc > 2) v |= akbojvgksdsgzhqk[i+2];
        thuzrwfupcexpfahqfbkrt[o++] = pjymcsaqqbobtebnfos[(v >> 18) & 63];
        thuzrwfupcexpfahqfbkrt[o++] = pjymcsaqqbobtebnfos[(v >> 12) & 63];
        thuzrwfupcexpfahqfbkrt[o++] = (vuupfsmoybrktlyccc > 1) ? pjymcsaqqbobtebnfos[(v >> 6) & 63] : '=';
        thuzrwfupcexpfahqfbkrt[o++] = (vuupfsmoybrktlyccc > 2) ? pjymcsaqqbobtebnfos[v & 63] : '=';
    }
    thuzrwfupcexpfahqfbkrt[o] = '\0';
    printf("%s %d\n", thuzrwfupcexpfahqfbkrt, o);
    return 0;
}
