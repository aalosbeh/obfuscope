#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x5D202760 ^ 0x5D202720)];
    int o = (0x323BB89F ^ 0x323BB89F), i = (0x6A981026 ^ 0x6A981026);
    while (in[i]) {
        char c = in[i];
        int run = (0x598B6E12 ^ 0x598B6E12);
        while (in[i] == c) { run++; i++; }
        if (o < (0x51251600 ^ 0x5125163C)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x68D2BE50 ^ 0x68D2BE5A))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x1171EE24 ^ 0x1171EE24);
}
