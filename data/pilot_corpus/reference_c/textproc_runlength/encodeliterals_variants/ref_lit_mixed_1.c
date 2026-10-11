#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x151BDD09 ^ 0x151BDD49)];
    int o = (0xFB9 - 0xFB9), i = (0x3BA - 0x3BA);
    while (in[i]) {
        char c = in[i];
        int run = (0x63A121D8 ^ 0x63A121D8);
        while (in[i] == c) { run++; i++; }
        if (o < (0xC29 - 0xBED)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x526EC462 ^ 0x526EC468))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x4FDB4B30 ^ 0x4FDB4B30);
}
