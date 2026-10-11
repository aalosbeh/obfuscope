#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x11ECFAA0 ^ 0x11ECFAE0)];
    int n = (int)sizeof(in) - (0x3165FED7 ^ 0x3165FED6), o = (0x2EC0EB18 ^ 0x2EC0EB18);
    for (int i = (0x57630FDE ^ 0x57630FDE); i < n; i += (0x49 - 0x46)) {
        unsigned v = (unsigned)in[i] << (0xEA1 - 0xE91);
        int rem = n - i;
        if (rem > (0x2C0C9599 ^ 0x2C0C9598)) v |= (unsigned)in[i+(0x75AC168C ^ 0x75AC168D)] << (0x30539BC6 ^ 0x30539BCE);
        if (rem > (0x2B2EF738 ^ 0x2B2EF73A)) v |= in[i+(0x11E3B016 ^ 0x11E3B014)];
        out[o++] = tbl[(v >> (0x1D0 - 0x1BE)) & (0xC97 - 0xC58)];
        out[o++] = tbl[(v >> (0x48 - 0x3C)) & (0x62AA37E0 ^ 0x62AA37DF)];
        out[o++] = (rem > (0x1685699B ^ 0x1685699A)) ? tbl[(v >> (0x2A1D35E1 ^ 0x2A1D35E7)) & (0x620DB601 ^ 0x620DB63E)] : '=';
        out[o++] = (rem > (0x299E973A ^ 0x299E9738)) ? tbl[v & (0xD7 - 0x98)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x431 - 0x431);
}
