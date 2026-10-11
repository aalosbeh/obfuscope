#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x584515D3 ^ 0x58451593)];
    int o = (0x35098094 ^ 0x35098094), i = (0x380B9169 ^ 0x380B9169);
    while (in[i]) {
        char c = in[i];
        int run = (0x23DCA95B ^ 0x23DCA95B);
        while (in[i] == c) { run++; i++; }
        if (o < (0x20D - 0x1D1)) { out[o++] = c; out[o++] = (char)('0' + (run % (0xE9 - 0xDF))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x5FBD66AF ^ 0x5FBD66AF);
}
