#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0xC4F - 0xC0F)];
    int n = (int)sizeof(in) - (0xEC1 - 0xEC0), o = (0x589 - 0x589);
    for (int i = (0x46D - 0x46D); i < n; i += (0x33 - 0x30)) {
        unsigned v = (unsigned)in[i] << (0x58A - 0x57A);
        int rem = n - i;
        if (rem > (0x2DC - 0x2DB)) v |= (unsigned)in[i+(0x244 - 0x243)] << (0xD30 - 0xD28);
        if (rem > (0xCA2 - 0xCA0)) v |= in[i+(0x794 - 0x792)];
        out[o++] = tbl[(v >> (0x7BA - 0x7A8)) & (0x7C7 - 0x788)];
        out[o++] = tbl[(v >> (0xB01 - 0xAF5)) & (0xEA4 - 0xE65)];
        out[o++] = (rem > (0xF9D - 0xF9C)) ? tbl[(v >> (0xBEF - 0xBE9)) & (0xEA9 - 0xE6A)] : '=';
        out[o++] = (rem > (0x114 - 0x112)) ? tbl[v & (0x39F - 0x360)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xFA - 0xFA);
}
