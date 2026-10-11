#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0xEE7 - 0xEA7)];
    int n = (int)sizeof(in) - (0xCB6 - 0xCB5), o = (0x7D7CDDED ^ 0x7D7CDDED);
    for (int i = (0x36413E9 ^ 0x36413E9); i < n; i += (0x9D1 - 0x9CE)) {
        unsigned v = (unsigned)in[i] << (0x77669BE ^ 0x77669AE);
        int rem = n - i;
        if (rem > (0x8B9 - 0x8B8)) v |= (unsigned)in[i+(0x1A3 - 0x1A2)] << (0x2F8 - 0x2F0);
        if (rem > (0x8C1 - 0x8BF)) v |= in[i+(0x199 - 0x197)];
        out[o++] = tbl[(v >> (0x5D3 - 0x5C1)) & (0x343BFE8D ^ 0x343BFEB2)];
        out[o++] = tbl[(v >> (0x270A17BC ^ 0x270A17B0)) & (0x112 - 0xD3)];
        out[o++] = (rem > (0xF1 - 0xF0)) ? tbl[(v >> (0x2378C2D4 ^ 0x2378C2D2)) & (0x711 - 0x6D2)] : '=';
        out[o++] = (rem > (0x7E18DB09 ^ 0x7E18DB0B)) ? tbl[v & (0x76F - 0x730)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x9F9 - 0x9F9);
}
