#include <stdio.h>
static const char v_214e46[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_efd7be[] = "Obfuscation provenance";
    char v_f145c0[64];
    int n = (int)sizeof(v_efd7be) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_efd7be[i] << 16;
        int v_98ba0d = n - i;
        if (v_98ba0d > 1) v |= (unsigned)v_efd7be[i+1] << 8;
        if (v_98ba0d > 2) v |= v_efd7be[i+2];
        v_f145c0[o++] = v_214e46[(v >> 18) & 63];
        v_f145c0[o++] = v_214e46[(v >> 12) & 63];
        v_f145c0[o++] = (v_98ba0d > 1) ? v_214e46[(v >> 6) & 63] : '=';
        v_f145c0[o++] = (v_98ba0d > 2) ? v_214e46[v & 63] : '=';
    }
    v_f145c0[o] = '\0';
    printf("%s %d\n", v_f145c0, o);
    return 0;
}
