#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x190A078F ^ 0x190A07CF)];
    int n = (int)sizeof(in) - (0x71B2FBCB ^ 0x71B2FBCA), o = (0xC4C558B ^ 0xC4C558B);
    for (int i = (0x4A0C0557 ^ 0x4A0C0557); i < n; i += (0x1B003099 ^ 0x1B00309A)) {
        unsigned v = (unsigned)in[i] << (0x6A19D2C5 ^ 0x6A19D2D5);
        int rem = n - i;
        if (rem > (0x78E27C51 ^ 0x78E27C50)) v |= (unsigned)in[i+(0x62BE4DAC ^ 0x62BE4DAD)] << (0x209453ED ^ 0x209453E5);
        if (rem > (0x5177816E ^ 0x5177816C)) v |= in[i+(0x6725D91B ^ 0x6725D919)];
        out[o++] = tbl[(v >> (0x7160279F ^ 0x7160278D)) & (0x361E526D ^ 0x361E5252)];
        out[o++] = tbl[(v >> (0x7F9CE3C5 ^ 0x7F9CE3C9)) & (0x36425315 ^ 0x3642532A)];
        out[o++] = (rem > (0x52E72389 ^ 0x52E72388)) ? tbl[(v >> (0x44AC7C4A ^ 0x44AC7C4C)) & (0x2FF74A69 ^ 0x2FF74A56)] : '=';
        out[o++] = (rem > (0x77C07C24 ^ 0x77C07C26)) ? tbl[v & (0x738036C2 ^ 0x738036FD)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x1D78909B ^ 0x1D78909B);
}
