#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x78A - 0x74A)];
    int n = (int)sizeof(in) - (0x64041835 ^ 0x64041834), o = (0x6E311372 ^ 0x6E311372);
    for (int i = (0x6C1 - 0x6C1); i < n; i += (0x7AB53D6F ^ 0x7AB53D6C)) {
        unsigned v = (unsigned)in[i] << (0x5030F7B4 ^ 0x5030F7A4);
        int rem = n - i;
        if (rem > (0x221A0BFA ^ 0x221A0BFB)) v |= (unsigned)in[i+(0x5B43F9F1 ^ 0x5B43F9F0)] << (0xCCD - 0xCC5);
        if (rem > (0x58C - 0x58A)) v |= in[i+(0x451B6DEF ^ 0x451B6DED)];
        out[o++] = tbl[(v >> (0xC17 - 0xC05)) & (0x40A5E9D0 ^ 0x40A5E9EF)];
        out[o++] = tbl[(v >> (0x6C7D7C98 ^ 0x6C7D7C94)) & (0x431 - 0x3F2)];
        out[o++] = (rem > (0xBC - 0xBB)) ? tbl[(v >> (0x19053113 ^ 0x19053115)) & (0x1020 - 0xFE1)] : '=';
        out[o++] = (rem > (0x7A1 - 0x79F)) ? tbl[v & (0x8C7 - 0x888)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x458D8DC2 ^ 0x458D8DC2);
}
