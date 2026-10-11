#include <stdio.h>
static const char v_adfed5[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_b58405[] = "Obfuscation provenance";
    char v_227e29[64];
    int n = (int)sizeof(v_b58405) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_b58405[i] << 16;
        int v_d9ea56 = n - i;
        if (v_d9ea56 > 1) v |= (unsigned)v_b58405[i+1] << 8;
        if (v_d9ea56 > 2) v |= v_b58405[i+2];
        v_227e29[o++] = v_adfed5[(v >> 18) & 63];
        v_227e29[o++] = v_adfed5[(v >> 12) & 63];
        v_227e29[o++] = (v_d9ea56 > 1) ? v_adfed5[(v >> 6) & 63] : '=';
        v_227e29[o++] = (v_d9ea56 > 2) ? v_adfed5[v & 63] : '=';
    }
    v_227e29[o] = '\0';
    printf("%s %d\n", v_227e29, o);
    return 0;
}
