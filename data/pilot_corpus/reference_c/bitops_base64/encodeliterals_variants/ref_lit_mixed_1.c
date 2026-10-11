#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x5E34957A ^ 0x5E34953A)];
    int n = (int)sizeof(in) - (0x6A1979FB ^ 0x6A1979FA), o = (0x2E4FFB55 ^ 0x2E4FFB55);
    for (int i = (0xED2 - 0xED2); i < n; i += (0xAE1 - 0xADE)) {
        unsigned v = (unsigned)in[i] << (0x497E48F2 ^ 0x497E48E2);
        int rem = n - i;
        if (rem > (0x7895BB74 ^ 0x7895BB75)) v |= (unsigned)in[i+(0x2A833E7B ^ 0x2A833E7A)] << (0x282867B9 ^ 0x282867B1);
        if (rem > (0x25805FDB ^ 0x25805FD9)) v |= in[i+(0x41629D2C ^ 0x41629D2E)];
        out[o++] = tbl[(v >> (0x14F3DAFE ^ 0x14F3DAEC)) & (0x69D - 0x65E)];
        out[o++] = tbl[(v >> (0xFEA - 0xFDE)) & (0xA54 - 0xA15)];
        out[o++] = (rem > (0xF45 - 0xF44)) ? tbl[(v >> (0x2C0 - 0x2BA)) & (0xD4DF9EE ^ 0xD4DF9D1)] : '=';
        out[o++] = (rem > (0x87C - 0x87A)) ? tbl[v & (0x3A7 - 0x368)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x3DA - 0x3DA);
}
