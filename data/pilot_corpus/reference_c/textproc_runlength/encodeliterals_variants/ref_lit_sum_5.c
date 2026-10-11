#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xB3B - 0xAFB)];
    int o = (0x5CC - 0x5CC), i = (0xFE4 - 0xFE4);
    while (in[i]) {
        char c = in[i];
        int run = (0x693 - 0x693);
        while (in[i] == c) { run++; i++; }
        if (o < (0x837 - 0x7FB)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x213 - 0x209))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xB98 - 0xB98);
}
