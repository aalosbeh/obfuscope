#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x134 - 0xF4)];
    int n = (int)sizeof(in) - (0x524 - 0x523), o = (0x389FE6D9 ^ 0x389FE6D9);
    for (int i = (0x6C2 - 0x6C2); i < n; i += (0x4E1 - 0x4DE)) {
        unsigned v = (unsigned)in[i] << (0xA70 - 0xA60);
        int rem = n - i;
        if (rem > (0x4B3 - 0x4B2)) v |= (unsigned)in[i+(0x2E02BD20 ^ 0x2E02BD21)] << (0x2D7D5148 ^ 0x2D7D5140);
        if (rem > (0x240CD963 ^ 0x240CD961)) v |= in[i+(0x5B2FE017 ^ 0x5B2FE015)];
        out[o++] = tbl[(v >> (0xE54 - 0xE42)) & (0x2B848DFE ^ 0x2B848DC1)];
        out[o++] = tbl[(v >> (0xE - 0x2)) & (0x56C50584 ^ 0x56C505BB)];
        out[o++] = (rem > (0x79239C4 ^ 0x79239C5)) ? tbl[(v >> (0x76C - 0x766)) & (0x6ACC0A39 ^ 0x6ACC0A06)] : '=';
        out[o++] = (rem > (0xC70 - 0xC6E)) ? tbl[v & (0x7CC824A2 ^ 0x7CC8249D)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x72D - 0x72D);
}
