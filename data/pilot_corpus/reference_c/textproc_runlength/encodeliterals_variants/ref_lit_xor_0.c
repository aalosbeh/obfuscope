#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x3CC87D31 ^ 0x3CC87D71)];
    int o = (0x4E0FCE31 ^ 0x4E0FCE31), i = (0x1F469729 ^ 0x1F469729);
    while (in[i]) {
        char c = in[i];
        int run = (0x6CDC7410 ^ 0x6CDC7410);
        while (in[i] == c) { run++; i++; }
        if (o < (0x335EDDA8 ^ 0x335EDD94)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x13CA4F27 ^ 0x13CA4F2D))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x4FA9DC57 ^ 0x4FA9DC57);
}
