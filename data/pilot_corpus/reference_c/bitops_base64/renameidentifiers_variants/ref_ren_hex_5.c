#include <stdio.h>
static const char v_8c2cf4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_c990be[] = "Obfuscation provenance";
    char v_eadd91[64];
    int n = (int)sizeof(v_c990be) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_c990be[i] << 16;
        int v_ec0712 = n - i;
        if (v_ec0712 > 1) v |= (unsigned)v_c990be[i+1] << 8;
        if (v_ec0712 > 2) v |= v_c990be[i+2];
        v_eadd91[o++] = v_8c2cf4[(v >> 18) & 63];
        v_eadd91[o++] = v_8c2cf4[(v >> 12) & 63];
        v_eadd91[o++] = (v_ec0712 > 1) ? v_8c2cf4[(v >> 6) & 63] : '=';
        v_eadd91[o++] = (v_ec0712 > 2) ? v_8c2cf4[v & 63] : '=';
    }
    v_eadd91[o] = '\0';
    printf("%s %d\n", v_eadd91, o);
    return 0;
}
