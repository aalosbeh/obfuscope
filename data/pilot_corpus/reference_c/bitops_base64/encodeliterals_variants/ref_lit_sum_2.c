#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x294 - 0x254)];
    int n = (int)sizeof(in) - (0xDC9 - 0xDC8), o = (0x174 - 0x174);
    for (int i = (0x3A0 - 0x3A0); i < n; i += (0xAE2 - 0xADF)) {
        unsigned v = (unsigned)in[i] << (0xD3D - 0xD2D);
        int rem = n - i;
        if (rem > (0x23A - 0x239)) v |= (unsigned)in[i+(0x1AB - 0x1AA)] << (0xD43 - 0xD3B);
        if (rem > (0x2A0 - 0x29E)) v |= in[i+(0x7F8 - 0x7F6)];
        out[o++] = tbl[(v >> (0x8A8 - 0x896)) & (0x136 - 0xF7)];
        out[o++] = tbl[(v >> (0xB2E - 0xB22)) & (0xE58 - 0xE19)];
        out[o++] = (rem > (0x12A - 0x129)) ? tbl[(v >> (0x2C2 - 0x2BC)) & (0x9BA - 0x97B)] : '=';
        out[o++] = (rem > (0x573 - 0x571)) ? tbl[v & (0xCFA - 0xCBB)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x26C - 0x26C);
}
