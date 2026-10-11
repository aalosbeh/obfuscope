#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x459EDBC2 ^ 0x459EDB82)];
    int o = (0x3446D347 ^ 0x3446D347), i = (0x3F45BF82 ^ 0x3F45BF82);
    while (in[i]) {
        char c = in[i];
        int run = (0x2C571207 ^ 0x2C571207);
        while (in[i] == c) { run++; i++; }
        if (o < (0x2CC13A27 ^ 0x2CC13A1B)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x376DF74 ^ 0x376DF7E))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x7B398057 ^ 0x7B398057);
}
