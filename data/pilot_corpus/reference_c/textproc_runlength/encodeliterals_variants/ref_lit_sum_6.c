#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x9E9 - 0x9A9)];
    int o = (0x7C3 - 0x7C3), i = (0x3A7 - 0x3A7);
    while (in[i]) {
        char c = in[i];
        int run = (0x88B - 0x88B);
        while (in[i] == c) { run++; i++; }
        if (o < (0x500 - 0x4C4)) { out[o++] = c; out[o++] = (char)('0' + (run % (0xEB1 - 0xEA7))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xC80 - 0xC80);
}
