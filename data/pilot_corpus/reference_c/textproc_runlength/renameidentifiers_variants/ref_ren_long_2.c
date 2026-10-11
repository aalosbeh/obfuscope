#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char bvirrjxslvzdwxazahhjf[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int whqjxmkblfinzskmaqanb = 0;
        while (in[i] == c) { whqjxmkblfinzskmaqanb++; i++; }
        if (o < 60) { bvirrjxslvzdwxazahhjf[o++] = c; bvirrjxslvzdwxazahhjf[o++] = (char)('0' + (whqjxmkblfinzskmaqanb % 10)); }
    }
    bvirrjxslvzdwxazahhjf[o] = '\0';
    printf("%s %d\n", bvirrjxslvzdwxazahhjf, o);
    return 0;
}
