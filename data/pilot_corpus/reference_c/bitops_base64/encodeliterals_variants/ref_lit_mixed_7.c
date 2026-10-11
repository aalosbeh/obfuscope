#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x628 - 0x5E8)];
    int n = (int)sizeof(in) - (0x2427E17F ^ 0x2427E17E), o = (0xD6E - 0xD6E);
    for (int i = (0x66C - 0x66C); i < n; i += (0xA5E - 0xA5B)) {
        unsigned v = (unsigned)in[i] << (0x8A9 - 0x899);
        int rem = n - i;
        if (rem > (0x357D10A5 ^ 0x357D10A4)) v |= (unsigned)in[i+(0x76E9B177 ^ 0x76E9B176)] << (0x7F7C7B53 ^ 0x7F7C7B5B);
        if (rem > (0xDB1 - 0xDAF)) v |= in[i+(0x863 - 0x861)];
        out[o++] = tbl[(v >> (0x496 - 0x484)) & (0x50E - 0x4CF)];
        out[o++] = tbl[(v >> (0x9AB - 0x99F)) & (0xC0F - 0xBD0)];
        out[o++] = (rem > (0xFE1 - 0xFE0)) ? tbl[(v >> (0x473F7BFF ^ 0x473F7BF9)) & (0xCA0 - 0xC61)] : '=';
        out[o++] = (rem > (0x636A5465 ^ 0x636A5467)) ? tbl[v & (0x12E - 0xEF)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x24E29E49 ^ 0x24E29E49);
}
