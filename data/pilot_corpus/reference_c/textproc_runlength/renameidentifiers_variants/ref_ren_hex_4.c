#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_a01727[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_9bba02 = 0;
        while (in[i] == c) { v_9bba02++; i++; }
        if (o < 60) { v_a01727[o++] = c; v_a01727[o++] = (char)('0' + (v_9bba02 % 10)); }
    }
    v_a01727[o] = '\0';
    printf("%s %d\n", v_a01727, o);
    return 0;
}
