#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x15145A5B ^ 0x15145A1B)];
    int o = (0x692 - 0x692), i = (0xBDA - 0xBDA);
    while (in[i]) {
        char c = in[i];
        int run = (0xE073A1F ^ 0xE073A1F);
        while (in[i] == c) { run++; i++; }
        if (o < (0x47C - 0x440)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x597A684 ^ 0x597A68E))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xE0 - 0xE0);
}
