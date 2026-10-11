#include <stdio.h>
static const char v_22a395[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_cf5cab[] = "Obfuscation provenance";
    char v_fea14f[64];
    int n = (int)sizeof(v_cf5cab) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_cf5cab[i] << 16;
        int v_da342f = n - i;
        if (v_da342f > 1) v |= (unsigned)v_cf5cab[i+1] << 8;
        if (v_da342f > 2) v |= v_cf5cab[i+2];
        v_fea14f[o++] = v_22a395[(v >> 18) & 63];
        v_fea14f[o++] = v_22a395[(v >> 12) & 63];
        v_fea14f[o++] = (v_da342f > 1) ? v_22a395[(v >> 6) & 63] : '=';
        v_fea14f[o++] = (v_da342f > 2) ? v_22a395[v & 63] : '=';
    }
    v_fea14f[o] = '\0';
    printf("%s %d\n", v_fea14f, o);
    return 0;
}
