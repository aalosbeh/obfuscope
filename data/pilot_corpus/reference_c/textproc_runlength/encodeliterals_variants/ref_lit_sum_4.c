#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xC83 - 0xC43)];
    int o = (0x387 - 0x387), i = (0x169 - 0x169);
    while (in[i]) {
        char c = in[i];
        int run = (0x60B - 0x60B);
        while (in[i] == c) { run++; i++; }
        if (o < (0x4CD - 0x491)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x2A4 - 0x29A))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x4D8 - 0x4D8);
}
