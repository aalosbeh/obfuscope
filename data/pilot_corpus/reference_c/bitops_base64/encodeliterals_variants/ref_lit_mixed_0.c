#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x5A0CE90 ^ 0x5A0CED0)];
    int n = (int)sizeof(in) - (0x1087F22D ^ 0x1087F22C), o = (0x1E231BC4 ^ 0x1E231BC4);
    for (int i = (0xE33 - 0xE33); i < n; i += (0x71B79FFC ^ 0x71B79FFF)) {
        unsigned v = (unsigned)in[i] << (0x19A12B44 ^ 0x19A12B54);
        int rem = n - i;
        if (rem > (0x5BE91B0 ^ 0x5BE91B1)) v |= (unsigned)in[i+(0xC2 - 0xC1)] << (0x4A991BAE ^ 0x4A991BA6);
        if (rem > (0x64D6E78E ^ 0x64D6E78C)) v |= in[i+(0x16 - 0x14)];
        out[o++] = tbl[(v >> (0x5C293E5A ^ 0x5C293E48)) & (0xFC4 - 0xF85)];
        out[o++] = tbl[(v >> (0xA63 - 0xA57)) & (0x5B48C07F ^ 0x5B48C040)];
        out[o++] = (rem > (0x7654C955 ^ 0x7654C954)) ? tbl[(v >> (0x74BFAA1C ^ 0x74BFAA1A)) & (0xB8B - 0xB4C)] : '=';
        out[o++] = (rem > (0x491 - 0x48F)) ? tbl[v & (0x660E117E ^ 0x660E1141)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xCC9 - 0xCC9);
}
