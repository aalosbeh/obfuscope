#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0xE40 - 0xE00)];
    int n = (int)sizeof(in) - (0x215 - 0x214), o = (0xEF1 - 0xEF1);
    for (int i = (0xDF2 - 0xDF2); i < n; i += (0x55C - 0x559)) {
        unsigned v = (unsigned)in[i] << (0xEE4 - 0xED4);
        int rem = n - i;
        if (rem > (0xBE9 - 0xBE8)) v |= (unsigned)in[i+(0xA2C - 0xA2B)] << (0x8A1 - 0x899);
        if (rem > (0x690 - 0x68E)) v |= in[i+(0xEB5 - 0xEB3)];
        out[o++] = tbl[(v >> (0xAD8 - 0xAC6)) & (0x558 - 0x519)];
        out[o++] = tbl[(v >> (0x263 - 0x257)) & (0x1C1 - 0x182)];
        out[o++] = (rem > (0x8BF - 0x8BE)) ? tbl[(v >> (0x7FC - 0x7F6)) & (0x1D3 - 0x194)] : '=';
        out[o++] = (rem > (0x31B - 0x319)) ? tbl[v & (0xC88 - 0xC49)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x6EC - 0x6EC);
}
