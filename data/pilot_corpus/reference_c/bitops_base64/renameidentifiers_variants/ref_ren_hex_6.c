#include <stdio.h>
static const char v_6c5eed[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_12c934[] = "Obfuscation provenance";
    char v_7633b7[64];
    int n = (int)sizeof(v_12c934) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_12c934[i] << 16;
        int v_ca1d5a = n - i;
        if (v_ca1d5a > 1) v |= (unsigned)v_12c934[i+1] << 8;
        if (v_ca1d5a > 2) v |= v_12c934[i+2];
        v_7633b7[o++] = v_6c5eed[(v >> 18) & 63];
        v_7633b7[o++] = v_6c5eed[(v >> 12) & 63];
        v_7633b7[o++] = (v_ca1d5a > 1) ? v_6c5eed[(v >> 6) & 63] : '=';
        v_7633b7[o++] = (v_ca1d5a > 2) ? v_6c5eed[v & 63] : '=';
    }
    v_7633b7[o] = '\0';
    printf("%s %d\n", v_7633b7, o);
    return 0;
}
