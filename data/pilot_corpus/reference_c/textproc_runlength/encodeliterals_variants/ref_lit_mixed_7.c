#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x8B - 0x4B)];
    int o = (0x1E6 - 0x1E6), i = (0x3C0 - 0x3C0);
    while (in[i]) {
        char c = in[i];
        int run = (0xA2E - 0xA2E);
        while (in[i] == c) { run++; i++; }
        if (o < (0x78891CFD ^ 0x78891CC1)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x551E170B ^ 0x551E1701))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x2CAA65AF ^ 0x2CAA65AF);
}
