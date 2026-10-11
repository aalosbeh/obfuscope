#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_3c7c19[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_172fc7 = 0;
        while (in[i] == c) { v_172fc7++; i++; }
        if (o < 60) { v_3c7c19[o++] = c; v_3c7c19[o++] = (char)('0' + (v_172fc7 % 10)); }
    }
    v_3c7c19[o] = '\0';
    printf("%s %d\n", v_3c7c19, o);
    return 0;
}
