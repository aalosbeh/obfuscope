#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char gmydbpoewzsumnizblkbp[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int rcydggrmsdvxgxks = 0;
        while (in[i] == c) { rcydggrmsdvxgxks++; i++; }
        if (o < 60) { gmydbpoewzsumnizblkbp[o++] = c; gmydbpoewzsumnizblkbp[o++] = (char)('0' + (rcydggrmsdvxgxks % 10)); }
    }
    gmydbpoewzsumnizblkbp[o] = '\0';
    printf("%s %d\n", gmydbpoewzsumnizblkbp, o);
    return 0;
}
