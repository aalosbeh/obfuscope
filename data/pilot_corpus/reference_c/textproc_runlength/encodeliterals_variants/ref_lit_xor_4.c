#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x59DC6F90 ^ 0x59DC6FD0)];
    int o = (0x754D9D84 ^ 0x754D9D84), i = (0x40848C33 ^ 0x40848C33);
    while (in[i]) {
        char c = in[i];
        int run = (0x67587CDE ^ 0x67587CDE);
        while (in[i] == c) { run++; i++; }
        if (o < (0x2A2071F ^ 0x2A20723)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x46031C62 ^ 0x46031C68))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x53B0D04B ^ 0x53B0D04B);
}
