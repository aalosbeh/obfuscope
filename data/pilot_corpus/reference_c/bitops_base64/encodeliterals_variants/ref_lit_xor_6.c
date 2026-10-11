#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x4FA3168E ^ 0x4FA316CE)];
    int n = (int)sizeof(in) - (0x5B554EC1 ^ 0x5B554EC0), o = (0x6CFDB4D ^ 0x6CFDB4D);
    for (int i = (0x1A7DB849 ^ 0x1A7DB849); i < n; i += (0x1D5B98AA ^ 0x1D5B98A9)) {
        unsigned v = (unsigned)in[i] << (0x5D301264 ^ 0x5D301274);
        int rem = n - i;
        if (rem > (0x139D8669 ^ 0x139D8668)) v |= (unsigned)in[i+(0x1DB612CE ^ 0x1DB612CF)] << (0x19CFEF14 ^ 0x19CFEF1C);
        if (rem > (0x1C391999 ^ 0x1C39199B)) v |= in[i+(0x2D240902 ^ 0x2D240900)];
        out[o++] = tbl[(v >> (0x4B17BD6D ^ 0x4B17BD7F)) & (0x2AA77D04 ^ 0x2AA77D3B)];
        out[o++] = tbl[(v >> (0x5992DD2 ^ 0x5992DDE)) & (0x49579A11 ^ 0x49579A2E)];
        out[o++] = (rem > (0x18FC1E23 ^ 0x18FC1E22)) ? tbl[(v >> (0x689FF4B3 ^ 0x689FF4B5)) & (0x62B93634 ^ 0x62B9360B)] : '=';
        out[o++] = (rem > (0x74A0ED84 ^ 0x74A0ED86)) ? tbl[v & (0x382405CC ^ 0x382405F3)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x5EC0EF38 ^ 0x5EC0EF38);
}
