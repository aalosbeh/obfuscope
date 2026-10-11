#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_4c83e8[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_7a5c87 = 0;
        while (in[i] == c) { v_7a5c87++; i++; }
        if (o < 60) { v_4c83e8[o++] = c; v_4c83e8[o++] = (char)('0' + (v_7a5c87 % 10)); }
    }
    v_4c83e8[o] = '\0';
    printf("%s %d\n", v_4c83e8, o);
    return 0;
}
