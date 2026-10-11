#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[(0x581531F7 ^ 0x581531B7)];
    int o = (0x26896CBB ^ 0x26896CBB), i = (0x192AC1B1 ^ 0x192AC1B1);
    while (in[i]) {
        char c = in[i];
        int run = (0x2A906DE7 ^ 0x2A906DE7);
        while (in[i] == c) { run++; i++; }
        if (o < (0x787540F ^ 0x7875433)) { out[o++] = c; out[o++] = (char)('0' + (run % (0x12DC74DF ^ 0x12DC74D5))); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return (0x2F9BE032 ^ 0x2F9BE032);
}
