#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x807 - 0x7C7)];
    int o = (0x5CB - 0x5CB), i = (0xC33 - 0xC33);
    while (in[i]) {
        char c = in[i];
        int run = (0xFCF - 0xFCF);
        while (in[i] == c) { run++; i++; }
        if (o < (0x431 - 0x3F5)) { out[o++] = c; out[o++] = (char)('0' + (run % (0xC53 - 0xC49))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xBAB - 0xBAB);
}
