#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x995 - 0x955)];
    int o = (0xF3B - 0xF3B), i = (0xB70 - 0xB70);
    while (in[i]) {
        char c = in[i];
        int run = (0x7BD - 0x7BD);
        while (in[i] == c) { run++; i++; }
        if (o < (0xA64 - 0xA28)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x6CD - 0x6C3))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x4FB - 0x4FB);
}
