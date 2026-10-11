#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x49A - 0x45A)];
    int n = (int)sizeof(in) - (0x4A1 - 0x4A0), o = (0xF0D - 0xF0D);
    for (int i = (0xDB5 - 0xDB5); i < n; i += (0xE0F - 0xE0C)) {
        unsigned v = (unsigned)in[i] << (0xC0B - 0xBFB);
        int rem = n - i;
        if (rem > (0x456 - 0x455)) v |= (unsigned)in[i+(0xE3 - 0xE2)] << (0x2B5 - 0x2AD);
        if (rem > (0x631 - 0x62F)) v |= in[i+(0x588 - 0x586)];
        out[o++] = tbl[(v >> (0xB4E - 0xB3C)) & (0x77E - 0x73F)];
        out[o++] = tbl[(v >> (0x2F2 - 0x2E6)) & (0x6FC - 0x6BD)];
        out[o++] = (rem > (0xA95 - 0xA94)) ? tbl[(v >> (0x3ED - 0x3E7)) & (0x93 - 0x54)] : '=';
        out[o++] = (rem > (0xC56 - 0xC54)) ? tbl[v & (0xD6F - 0xD30)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x197 - 0x197);
}
