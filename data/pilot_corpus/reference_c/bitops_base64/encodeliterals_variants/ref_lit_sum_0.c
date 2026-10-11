#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0xCD9 - 0xC99)];
    int n = (int)sizeof(in) - (0x88B - 0x88A), o = (0xD6A - 0xD6A);
    for (int i = (0xEFE - 0xEFE); i < n; i += (0x526 - 0x523)) {
        unsigned v = (unsigned)in[i] << (0xA56 - 0xA46);
        int rem = n - i;
        if (rem > (0xC2F - 0xC2E)) v |= (unsigned)in[i+(0x19D - 0x19C)] << (0x445 - 0x43D);
        if (rem > (0x6CD - 0x6CB)) v |= in[i+(0xB63 - 0xB61)];
        out[o++] = tbl[(v >> (0xD7B - 0xD69)) & (0x9F9 - 0x9BA)];
        out[o++] = tbl[(v >> (0x226 - 0x21A)) & (0x4B9 - 0x47A)];
        out[o++] = (rem > (0x555 - 0x554)) ? tbl[(v >> (0x50 - 0x4A)) & (0xDE2 - 0xDA3)] : '=';
        out[o++] = (rem > (0xCA5 - 0xCA3)) ? tbl[v & (0x7AD - 0x76E)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xC02 - 0xC02);
}
