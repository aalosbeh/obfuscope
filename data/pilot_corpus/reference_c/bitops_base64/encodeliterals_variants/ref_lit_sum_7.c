#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x2E2 - 0x2A2)];
    int n = (int)sizeof(in) - (0x849 - 0x848), o = (0x64B - 0x64B);
    for (int i = (0x77F - 0x77F); i < n; i += (0x588 - 0x585)) {
        unsigned v = (unsigned)in[i] << (0x620 - 0x610);
        int rem = n - i;
        if (rem > (0x614 - 0x613)) v |= (unsigned)in[i+(0x864 - 0x863)] << (0x6E9 - 0x6E1);
        if (rem > (0x576 - 0x574)) v |= in[i+(0x3DE - 0x3DC)];
        out[o++] = tbl[(v >> (0xA71 - 0xA5F)) & (0x6E7 - 0x6A8)];
        out[o++] = tbl[(v >> (0x3B1 - 0x3A5)) & (0x64 - 0x25)];
        out[o++] = (rem > (0x5B3 - 0x5B2)) ? tbl[(v >> (0x12C - 0x126)) & (0x12A - 0xEB)] : '=';
        out[o++] = (rem > (0x3F3 - 0x3F1)) ? tbl[v & (0x375 - 0x336)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xF78 - 0xF78);
}
