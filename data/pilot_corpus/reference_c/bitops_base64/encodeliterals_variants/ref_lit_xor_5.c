#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x79311CDD ^ 0x79311C9D)];
    int n = (int)sizeof(in) - (0x20D64CC3 ^ 0x20D64CC2), o = (0x5E071EC7 ^ 0x5E071EC7);
    for (int i = (0x2DB4E1BE ^ 0x2DB4E1BE); i < n; i += (0x27C41CBB ^ 0x27C41CB8)) {
        unsigned v = (unsigned)in[i] << (0x1E6C5584 ^ 0x1E6C5594);
        int rem = n - i;
        if (rem > (0x3DDD6C16 ^ 0x3DDD6C17)) v |= (unsigned)in[i+(0x76BD60E ^ 0x76BD60F)] << (0x363C3D68 ^ 0x363C3D60);
        if (rem > (0x1889809F ^ 0x1889809D)) v |= in[i+(0x52FC3F35 ^ 0x52FC3F37)];
        out[o++] = tbl[(v >> (0x28FF1B9F ^ 0x28FF1B8D)) & (0x2ECFE09 ^ 0x2ECFE36)];
        out[o++] = tbl[(v >> (0x3FAF3958 ^ 0x3FAF3954)) & (0x227F4E47 ^ 0x227F4E78)];
        out[o++] = (rem > (0x6917865F ^ 0x6917865E)) ? tbl[(v >> (0x71228D38 ^ 0x71228D3E)) & (0x40DFA05E ^ 0x40DFA061)] : '=';
        out[o++] = (rem > (0x4FE0FACA ^ 0x4FE0FAC8)) ? tbl[v & (0x53BBF3E2 ^ 0x53BBF3DD)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x6A3057B5 ^ 0x6A3057B5);
}
