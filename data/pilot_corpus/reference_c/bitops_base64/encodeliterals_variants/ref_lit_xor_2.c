#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x425416A9 ^ 0x425416E9)];
    int n = (int)sizeof(in) - (0xF93F8B3 ^ 0xF93F8B2), o = (0x3AB17159 ^ 0x3AB17159);
    for (int i = (0x61B322FE ^ 0x61B322FE); i < n; i += (0x25F52C84 ^ 0x25F52C87)) {
        unsigned v = (unsigned)in[i] << (0x597DE6CD ^ 0x597DE6DD);
        int rem = n - i;
        if (rem > (0x1E27884 ^ 0x1E27885)) v |= (unsigned)in[i+(0x2D32F22F ^ 0x2D32F22E)] << (0x43BF6C25 ^ 0x43BF6C2D);
        if (rem > (0x7F19A00B ^ 0x7F19A009)) v |= in[i+(0x7F493DA2 ^ 0x7F493DA0)];
        out[o++] = tbl[(v >> (0x3880E18D ^ 0x3880E19F)) & (0x1E4B154E ^ 0x1E4B1571)];
        out[o++] = tbl[(v >> (0x74066ABC ^ 0x74066AB0)) & (0x17C9FFF5 ^ 0x17C9FFCA)];
        out[o++] = (rem > (0x6F2314CA ^ 0x6F2314CB)) ? tbl[(v >> (0x4291F310 ^ 0x4291F316)) & (0x6FDF6250 ^ 0x6FDF626F)] : '=';
        out[o++] = (rem > (0x537D7E32 ^ 0x537D7E30)) ? tbl[v & (0x1257796F ^ 0x12577950)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x5B753F94 ^ 0x5B753F94);
}
