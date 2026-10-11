#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_ede00b[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_812797 = 0;
        while (in[i] == c) { v_812797++; i++; }
        if (o < 60) { v_ede00b[o++] = c; v_ede00b[o++] = (char)('0' + (v_812797 % 10)); }
    }
    v_ede00b[o] = '\0';
    printf("%s %d\n", v_ede00b, o);
    return 0;
}
