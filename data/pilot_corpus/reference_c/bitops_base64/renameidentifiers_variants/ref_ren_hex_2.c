#include <stdio.h>
static const char v_c0104e[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_2bb087[] = "Obfuscation provenance";
    char v_afbee4[64];
    int n = (int)sizeof(v_2bb087) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_2bb087[i] << 16;
        int v_c5fd10 = n - i;
        if (v_c5fd10 > 1) v |= (unsigned)v_2bb087[i+1] << 8;
        if (v_c5fd10 > 2) v |= v_2bb087[i+2];
        v_afbee4[o++] = v_c0104e[(v >> 18) & 63];
        v_afbee4[o++] = v_c0104e[(v >> 12) & 63];
        v_afbee4[o++] = (v_c5fd10 > 1) ? v_c0104e[(v >> 6) & 63] : '=';
        v_afbee4[o++] = (v_c5fd10 > 2) ? v_c0104e[v & 63] : '=';
    }
    v_afbee4[o] = '\0';
    printf("%s %d\n", v_afbee4, o);
    return 0;
}
