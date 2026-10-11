#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char atyrmmezckonyms[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int bsryhvpyobqfig = 0;
        while (in[i] == c) { bsryhvpyobqfig++; i++; }
        if (o < 60) { atyrmmezckonyms[o++] = c; atyrmmezckonyms[o++] = (char)('0' + (bsryhvpyobqfig % 10)); }
    }
    atyrmmezckonyms[o] = '\0';
    printf("%s %d\n", atyrmmezckonyms, o);
    return 0;
}
