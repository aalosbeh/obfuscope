#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xAA37672 ^ 0xAA37632)];
    int o = (0x77DAE64E ^ 0x77DAE64E), i = (0x5546F94C ^ 0x5546F94C);
    while (in[i]) {
        char c = in[i];
        int run = (0x35A2C095 ^ 0x35A2C095);
        while (in[i] == c) { run++; i++; }
        if (o < (0x684E37A9 ^ 0x684E3795)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x646C06B7 ^ 0x646C06BD))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x7B329406 ^ 0x7B329406);
}
