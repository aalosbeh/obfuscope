#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0xD88 - 0xD48)];
    int o = (0xBFF - 0xBFF), i = (0xE73 - 0xE73);
    while (in[i]) {
        char c = in[i];
        int run = (0xBF8 - 0xBF8);
        while (in[i] == c) { run++; i++; }
        if (o < (0xA92 - 0xA56)) { out[o++] = c; out[o++] = (char)('0' + (run % (0xA22 - 0xA18))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0xF65 - 0xF65);
}
