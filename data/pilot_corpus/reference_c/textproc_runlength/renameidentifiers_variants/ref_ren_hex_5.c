#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_a9d389[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_978ecf = 0;
        while (in[i] == c) { v_978ecf++; i++; }
        if (o < 60) { v_a9d389[o++] = c; v_a9d389[o++] = (char)('0' + (v_978ecf % 10)); }
    }
    v_a9d389[o] = '\0';
    printf("%s %d\n", v_a9d389, o);
    return 0;
}
