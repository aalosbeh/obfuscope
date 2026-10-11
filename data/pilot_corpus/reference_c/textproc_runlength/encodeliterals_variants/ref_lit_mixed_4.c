#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xC69 - 0xC29)];
    int o = (0x6D706F64 ^ 0x6D706F64), i = (0xADB - 0xADB);
    while (in[i]) {
        char c = in[i];
        int run = (0x898 - 0x898);
        while (in[i] == c) { run++; i++; }
        if (o < (0xCFE - 0xCC2)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x8B - 0x81))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x5BAF628 ^ 0x5BAF628);
}
