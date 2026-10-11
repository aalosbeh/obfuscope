#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char v_10421a[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int v_10396b = 0;
        while (in[i] == c) { v_10396b++; i++; }
        if (o < 60) { v_10421a[o++] = c; v_10421a[o++] = (char)('0' + (v_10396b % 10)); }
    }
    v_10421a[o] = '\0';
    printf("%s %d\n", v_10421a, o);
    return 0;
}
