#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_d85160[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_84c5fe = 0;
        while (in[i] == c) { v_84c5fe++; i++; }
        if (o < 60) { v_d85160[o++] = c; v_d85160[o++] = (char)('0' + (v_84c5fe % 10)); }
    }
    v_d85160[o] = '\0';
    printf("%s %d\n", v_d85160, o);
    return 0;
}
