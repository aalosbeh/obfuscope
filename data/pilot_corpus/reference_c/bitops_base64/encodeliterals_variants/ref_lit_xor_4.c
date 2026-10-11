#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x5F4CE3F ^ 0x5F4CE7F)];
    int n = (int)sizeof(in) - (0x65750E40 ^ 0x65750E41), o = (0x10F19E83 ^ 0x10F19E83);
    for (int i = (0x6FD98556 ^ 0x6FD98556); i < n; i += (0x22AE127F ^ 0x22AE127C)) {
        unsigned v = (unsigned)in[i] << (0x3D6D9283 ^ 0x3D6D9293);
        int rem = n - i;
        if (rem > (0x216A8892 ^ 0x216A8893)) v |= (unsigned)in[i+(0x715A1762 ^ 0x715A1763)] << (0x9CEC6CD ^ 0x9CEC6C5);
        if (rem > (0x8B588AF ^ 0x8B588AD)) v |= in[i+(0x4628C72D ^ 0x4628C72F)];
        out[o++] = tbl[(v >> (0x58D2F87B ^ 0x58D2F869)) & (0x34C3102 ^ 0x34C313D)];
        out[o++] = tbl[(v >> (0x486CC14C ^ 0x486CC140)) & (0x7B22819A ^ 0x7B2281A5)];
        out[o++] = (rem > (0x34D7490B ^ 0x34D7490A)) ? tbl[(v >> (0x3FDC0B15 ^ 0x3FDC0B13)) & (0x3284291A ^ 0x32842925)] : '=';
        out[o++] = (rem > (0x5B0EAC3 ^ 0x5B0EAC1)) ? tbl[v & (0x9A4F669 ^ 0x9A4F656)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x4593BC36 ^ 0x4593BC36);
}
