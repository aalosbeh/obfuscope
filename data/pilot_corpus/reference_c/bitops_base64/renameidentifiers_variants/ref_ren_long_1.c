#include <stdio.h>
static const char fwwwhlrpajagbfsyiqf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char gjkksmnokmquyf[] = "Obfuscation provenance";
    char qdwdqqxdlukhnyekcqepa[64];
    int n = (int)sizeof(gjkksmnokmquyf) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)gjkksmnokmquyf[i] << 16;
        int fllbrzkulaqmmijk = n - i;
        if (fllbrzkulaqmmijk > 1) v |= (unsigned)gjkksmnokmquyf[i+1] << 8;
        if (fllbrzkulaqmmijk > 2) v |= gjkksmnokmquyf[i+2];
        qdwdqqxdlukhnyekcqepa[o++] = fwwwhlrpajagbfsyiqf[(v >> 18) & 63];
        qdwdqqxdlukhnyekcqepa[o++] = fwwwhlrpajagbfsyiqf[(v >> 12) & 63];
        qdwdqqxdlukhnyekcqepa[o++] = (fllbrzkulaqmmijk > 1) ? fwwwhlrpajagbfsyiqf[(v >> 6) & 63] : '=';
        qdwdqqxdlukhnyekcqepa[o++] = (fllbrzkulaqmmijk > 2) ? fwwwhlrpajagbfsyiqf[v & 63] : '=';
    }
    qdwdqqxdlukhnyekcqepa[o] = '\0';
    printf("%s %d\n", qdwdqqxdlukhnyekcqepa, o);
    return 0;
}
