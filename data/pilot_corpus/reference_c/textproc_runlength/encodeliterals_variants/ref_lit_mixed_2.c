#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x3EFCECF3 ^ 0x3EFCECB3)];
    int o = (0x60BA407F ^ 0x60BA407F), i = (0x2E2 - 0x2E2);
    while (in[i]) {
        char c = in[i];
        int run = (0x55545582 ^ 0x55545582);
        while (in[i] == c) { run++; i++; }
        if (o < (0x19D - 0x161)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x498D6F3B ^ 0x498D6F31))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x1C - 0x1C);
}
