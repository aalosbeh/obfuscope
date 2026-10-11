#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_8d4e07[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_dd16fb = 0;
        while (in[i] == c) { v_dd16fb++; i++; }
        if (o < 60) { v_8d4e07[o++] = c; v_8d4e07[o++] = (char)('0' + (v_dd16fb % 10)); }
    }
    v_8d4e07[o] = '\0';
    printf("%s %d\n", v_8d4e07, o);
    return 0;
}
