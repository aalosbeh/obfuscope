#include <stdio.h>
static const char v_567b31[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char v_ddac81[] = "Obfuscation provenance";
    char v_53cb25[64];
    int n = (int)sizeof(v_ddac81) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)v_ddac81[i] << 16;
        int v_6bcb22 = n - i;
        if (v_6bcb22 > 1) v |= (unsigned)v_ddac81[i+1] << 8;
        if (v_6bcb22 > 2) v |= v_ddac81[i+2];
        v_53cb25[o++] = v_567b31[(v >> 18) & 63];
        v_53cb25[o++] = v_567b31[(v >> 12) & 63];
        v_53cb25[o++] = (v_6bcb22 > 1) ? v_567b31[(v >> 6) & 63] : '=';
        v_53cb25[o++] = (v_6bcb22 > 2) ? v_567b31[v & 63] : '=';
    }
    v_53cb25[o] = '\0';
    printf("%s %d\n", v_53cb25, o);
    return 0;
}
