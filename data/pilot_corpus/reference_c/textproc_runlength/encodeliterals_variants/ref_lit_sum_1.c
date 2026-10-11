#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xF9 - 0xB9)];
    int o = (0x6F8 - 0x6F8), i = (0xA3A - 0xA3A);
    while (in[i]) {
        char c = in[i];
        int run = (0x3AC - 0x3AC);
        while (in[i] == c) { run++; i++; }
        if (o < (0xAB5 - 0xA79)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x411 - 0x407))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xCA1 - 0xCA1);
}
