#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x9F3 - 0x9B3)];
    int n = (int)sizeof(in) - (0xBE3 - 0xBE2), o = (0x60E738FA ^ 0x60E738FA);
    for (int i = (0x186 - 0x186); i < n; i += (0x47B2B1B0 ^ 0x47B2B1B3)) {
        unsigned v = (unsigned)in[i] << (0x25408C15 ^ 0x25408C05);
        int rem = n - i;
        if (rem > (0x1D8E0DAD ^ 0x1D8E0DAC)) v |= (unsigned)in[i+(0xC0F406A ^ 0xC0F406B)] << (0x6B41BAF9 ^ 0x6B41BAF1);
        if (rem > (0x4F9 - 0x4F7)) v |= in[i+(0x67C - 0x67A)];
        out[o++] = tbl[(v >> (0x3BCAC71 ^ 0x3BCAC63)) & (0xCF7 - 0xCB8)];
        out[o++] = tbl[(v >> (0xBA2 - 0xB96)) & (0x68E32655 ^ 0x68E3266A)];
        out[o++] = (rem > (0xAB8 - 0xAB7)) ? tbl[(v >> (0x4211E80B ^ 0x4211E80D)) & (0x9DC - 0x99D)] : '=';
        out[o++] = (rem > (0xB48 - 0xB46)) ? tbl[v & (0x4E6 - 0x4A7)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x16E - 0x16E);
}
