#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x804 - 0x7C4)];
    int n = (int)sizeof(in) - (0x654 - 0x653), o = (0x65F - 0x65F);
    for (int i = (0xE7B - 0xE7B); i < n; i += (0x80B - 0x808)) {
        unsigned v = (unsigned)in[i] << (0x3BF - 0x3AF);
        int rem = n - i;
        if (rem > (0xD15 - 0xD14)) v |= (unsigned)in[i+(0xEAC - 0xEAB)] << (0x46C - 0x464);
        if (rem > (0xF61 - 0xF5F)) v |= in[i+(0x261 - 0x25F)];
        out[o++] = tbl[(v >> (0x5C2 - 0x5B0)) & (0x9D8 - 0x999)];
        out[o++] = tbl[(v >> (0xE52 - 0xE46)) & (0xAB4 - 0xA75)];
        out[o++] = (rem > (0xFFE - 0xFFD)) ? tbl[(v >> (0xFD8 - 0xFD2)) & (0x69F - 0x660)] : '=';
        out[o++] = (rem > (0xD2E - 0xD2C)) ? tbl[v & (0x98 - 0x59)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x6C3 - 0x6C3);
}
