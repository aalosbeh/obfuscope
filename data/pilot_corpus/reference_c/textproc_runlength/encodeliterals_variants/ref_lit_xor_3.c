#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x786ABDA8 ^ 0x786ABDE8)];
    int o = (0x255314DA ^ 0x255314DA), i = (0x469F0BE8 ^ 0x469F0BE8);
    while (in[i]) {
        char c = in[i];
        int run = (0x315B2683 ^ 0x315B2683);
        while (in[i] == c) { run++; i++; }
        if (o < (0x194D952C ^ 0x194D9510)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x406044D7 ^ 0x406044DD))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x3C723603 ^ 0x3C723603);
}
