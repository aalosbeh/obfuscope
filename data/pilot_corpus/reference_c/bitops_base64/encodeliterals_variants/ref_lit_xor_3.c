#include <stdio.h>
static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[(0x724253ED ^ 0x724253AD)];
    int n = (int)sizeof(in) - (0x5D7DA1D0 ^ 0x5D7DA1D1), o = (0x4B394B1B ^ 0x4B394B1B);
    for (int i = (0x4E39F628 ^ 0x4E39F628); i < n; i += (0x48706CAF ^ 0x48706CAC)) {
        unsigned v = (unsigned)in[i] << (0x189783F1 ^ 0x189783E1);
        int rem = n - i;
        if (rem > (0xB211193 ^ 0xB211192)) v |= (unsigned)in[i+(0x42354F1F ^ 0x42354F1E)] << (0x3870453C ^ 0x38704534);
        if (rem > (0x36F2C754 ^ 0x36F2C756)) v |= in[i+(0x4AC73FEA ^ 0x4AC73FE8)];
        out[o++] = tbl[(v >> (0x2AC52F42 ^ 0x2AC52F50)) & (0x69CA24A3 ^ 0x69CA249C)];
        out[o++] = tbl[(v >> (0x7FEF37FB ^ 0x7FEF37F7)) & (0x1E1D21AC ^ 0x1E1D2193)];
        out[o++] = (rem > (0x7B5EC120 ^ 0x7B5EC121)) ? tbl[(v >> (0x6618BE9D ^ 0x6618BE9B)) & (0x5A1AE72D ^ 0x5A1AE712)] : '=';
        out[o++] = (rem > (0x74A44913 ^ 0x74A44911)) ? tbl[v & (0x48EA0527 ^ 0x48EA0518)] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x5F323471 ^ 0x5F323471);
}
