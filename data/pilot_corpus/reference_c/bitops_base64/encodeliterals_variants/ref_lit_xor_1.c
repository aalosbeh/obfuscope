#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x3B9FAA89 ^ 0x3B9FAAC9)];
    int n = (int)sizeof(in) - (0x4FB0E933 ^ 0x4FB0E932), o = (0x3B1CCBB6 ^ 0x3B1CCBB6);
    for (int i = (0x72540147 ^ 0x72540147); i < n; i += (0x1984F9A5 ^ 0x1984F9A6)) {
        unsigned v = (unsigned)in[i] << (0x4B794F67 ^ 0x4B794F77);
        int rem = n - i;
        if (rem > (0x66F7A650 ^ 0x66F7A651)) v |= (unsigned)in[i+(0x50E04A27 ^ 0x50E04A26)] << (0x62AF8251 ^ 0x62AF8259);
        if (rem > (0x2ADDB8AB ^ 0x2ADDB8A9)) v |= in[i+(0x71A13177 ^ 0x71A13175)];
        out[o++] = tbl[(v >> (0x108C874E ^ 0x108C875C)) & (0x6FF8421E ^ 0x6FF84221)];
        out[o++] = tbl[(v >> (0x264B6704 ^ 0x264B6708)) & (0xCD0253E ^ 0xCD02501)];
        out[o++] = (rem > (0x5A0A821D ^ 0x5A0A821C)) ? tbl[(v >> (0x45D02AE7 ^ 0x45D02AE1)) & (0x562CA183 ^ 0x562CA1BC)] : '=';
        out[o++] = (rem > (0x6634F76 ^ 0x6634F74)) ? tbl[v & (0x7865B546 ^ 0x7865B579)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x328A2E3 ^ 0x328A2E3);
}
