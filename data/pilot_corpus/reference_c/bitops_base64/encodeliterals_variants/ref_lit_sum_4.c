#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0xC22 - 0xBE2)];
    int n = (int)sizeof(in) - (0x459 - 0x458), o = (0xDA4 - 0xDA4);
    for (int i = (0x369 - 0x369); i < n; i += (0x83B - 0x838)) {
        unsigned v = (unsigned)in[i] << (0x8C9 - 0x8B9);
        int rem = n - i;
        if (rem > (0x908 - 0x907)) v |= (unsigned)in[i+(0xCA5 - 0xCA4)] << (0x32E - 0x326);
        if (rem > (0x1B5 - 0x1B3)) v |= in[i+(0x5FC - 0x5FA)];
        out[o++] = tbl[(v >> (0x8A7 - 0x895)) & (0x96D - 0x92E)];
        out[o++] = tbl[(v >> (0x7C6 - 0x7BA)) & (0x542 - 0x503)];
        out[o++] = (rem > (0x114 - 0x113)) ? tbl[(v >> (0xF86 - 0xF80)) & (0x56 - 0x17)] : '=';
        out[o++] = (rem > (0x7B5 - 0x7B3)) ? tbl[v & (0xFDA - 0xF9B)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x384 - 0x384);
}
