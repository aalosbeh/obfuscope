#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x70A - 0x6CA)];
    int o = (0x5B0DD6FB ^ 0x5B0DD6FB), i = (0x92E - 0x92E);
    while (in[i]) {
        char c = in[i];
        int run = (0xAA9 - 0xAA9);
        while (in[i] == c) { run++; i++; }
        if (o < (0x723 - 0x6E7)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x15A - 0x150))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x52CE908B ^ 0x52CE908B);
}
