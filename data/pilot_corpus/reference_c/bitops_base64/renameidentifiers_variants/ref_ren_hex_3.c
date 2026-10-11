#include <stdio.h>
static const char v_75d206[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_332d24[] = "Obfuscation provenance";
    char v_3662d4[64];
    int n = (int)sizeof(v_332d24) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_332d24[i] << 16;
        int v_c06948 = n - i;
        if (v_c06948 > 1) v |= (unsigned)v_332d24[i+1] << 8;
        if (v_c06948 > 2) v |= v_332d24[i+2];
        v_3662d4[o++] = v_75d206[(v >> 18) & 63];
        v_3662d4[o++] = v_75d206[(v >> 12) & 63];
        v_3662d4[o++] = (v_c06948 > 1) ? v_75d206[(v >> 6) & 63] : '=';
        v_3662d4[o++] = (v_c06948 > 2) ? v_75d206[v & 63] : '=';
    }
    v_3662d4[o] = '\0';
    printf("%s %d\n", v_3662d4, o);
    return 0;
}
