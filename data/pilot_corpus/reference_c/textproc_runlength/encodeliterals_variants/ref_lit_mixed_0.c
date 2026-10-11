#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x5292F4B8 ^ 0x5292F4F8)];
    int o = (0x2DC27D16 ^ 0x2DC27D16), i = (0xB7A - 0xB7A);
    while (in[i]) {
        char c = in[i];
        int run = (0x7477B1AE ^ 0x7477B1AE);
        while (in[i] == c) { run++; i++; }
        if (o < (0x4FE1C4EC ^ 0x4FE1C4D0)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x7FE447D2 ^ 0x7FE447D8))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x1EF83797 ^ 0x1EF83797);
}
