#include <stdio.h>
static const char ddqmcrbseeprnvj[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char qmpelbfebgfcjgawuac[] = "Obfuscation provenance";
    char vmtrxxmsrgfzufgoeeiqo[64];
    int n = (int)sizeof(qmpelbfebgfcjgawuac) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)qmpelbfebgfcjgawuac[i] << 16;
        int ekojspmrxqezfc = n - i;
        if (ekojspmrxqezfc > 1) v |= (unsigned)qmpelbfebgfcjgawuac[i+1] << 8;
        if (ekojspmrxqezfc > 2) v |= qmpelbfebgfcjgawuac[i+2];
        vmtrxxmsrgfzufgoeeiqo[o++] = ddqmcrbseeprnvj[(v >> 18) & 63];
        vmtrxxmsrgfzufgoeeiqo[o++] = ddqmcrbseeprnvj[(v >> 12) & 63];
        vmtrxxmsrgfzufgoeeiqo[o++] = (ekojspmrxqezfc > 1) ? ddqmcrbseeprnvj[(v >> 6) & 63] : '=';
        vmtrxxmsrgfzufgoeeiqo[o++] = (ekojspmrxqezfc > 2) ? ddqmcrbseeprnvj[v & 63] : '=';
    }
    vmtrxxmsrgfzufgoeeiqo[o] = '\0';
    printf("%s %d\n", vmtrxxmsrgfzufgoeeiqo, o);
    return 0;
}
