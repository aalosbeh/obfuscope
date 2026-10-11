#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x33CC10FB ^ 0x33CC10BB)];
    int o = (0x76501BB9 ^ 0x76501BB9), i = (0x361ED3D7 ^ 0x361ED3D7);
    while (in[i]) {
        char c = in[i];
        int run = (0x588B21E3 ^ 0x588B21E3);
        while (in[i] == c) { run++; i++; }
        if (o < (0x23175127 ^ 0x2317511B)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x3DA74D4A ^ 0x3DA74D40))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x5A2923B ^ 0x5A2923B);
}
