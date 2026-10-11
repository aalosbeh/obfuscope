#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x1E78520A ^ 0x1E78524A)];
    int n = (int)sizeof(in) - (0x2A8C3855 ^ 0x2A8C3854), o = (0x3FE92DFB ^ 0x3FE92DFB);
    for (int i = (0x23D45935 ^ 0x23D45935); i < n; i += (0x1AADFEC2 ^ 0x1AADFEC1)) {
        unsigned v = (unsigned)in[i] << (0x7BF6A031 ^ 0x7BF6A021);
        int rem = n - i;
        if (rem > (0x1B272B5E ^ 0x1B272B5F)) v |= (unsigned)in[i+(0xB7F56D5 ^ 0xB7F56D4)] << (0x535D2EAB ^ 0x535D2EA3);
        if (rem > (0x17B0D23F ^ 0x17B0D23D)) v |= in[i+(0x85CE9C ^ 0x85CE9E)];
        out[o++] = tbl[(v >> (0x4771009C ^ 0x4771008E)) & (0x10F9B65A ^ 0x10F9B665)];
        out[o++] = tbl[(v >> (0x7445FDF ^ 0x7445FD3)) & (0x4BF22323 ^ 0x4BF2231C)];
        out[o++] = (rem > (0x7BF7CC9E ^ 0x7BF7CC9F)) ? tbl[(v >> (0x190B8E12 ^ 0x190B8E14)) & (0x66A1066B ^ 0x66A10654)] : '=';
        out[o++] = (rem > (0x2B6F3440 ^ 0x2B6F3442)) ? tbl[v & (0x15F1AA9A ^ 0x15F1AAA5)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x57936037 ^ 0x57936037);
}
