#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char wfdbkhzbuzurrlxrltp[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int jisboiwpkvzgvs = 0;
        while (in[i] == c) { jisboiwpkvzgvs++; i++; }
        if (o < 60) { wfdbkhzbuzurrlxrltp[o++] = c; wfdbkhzbuzurrlxrltp[o++] = (char)('0' + (jisboiwpkvzgvs % 10)); }
    }
    wfdbkhzbuzurrlxrltp[o] = '\0';
    printf("%s %d\n", wfdbkhzbuzurrlxrltp, o);
    return 0;
}
