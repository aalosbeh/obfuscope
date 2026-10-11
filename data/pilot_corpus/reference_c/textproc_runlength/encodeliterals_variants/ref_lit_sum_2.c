#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xDF4 - 0xDB4)];
    int o = (0xB34 - 0xB34), i = (0xC83 - 0xC83);
    while (in[i]) {
        char c = in[i];
        int run = (0xD17 - 0xD17);
        while (in[i] == c) { run++; i++; }
        if (o < (0xAF3 - 0xAB7)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x546 - 0x53C))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x215 - 0x215);
}
