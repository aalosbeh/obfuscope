#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char iirnpmpxcjwwcqosywx[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int bqsdygqhwtiyusknfrm = 0;
        while (in[i] == c) { bqsdygqhwtiyusknfrm++; i++; }
        if (o < 60) { iirnpmpxcjwwcqosywx[o++] = c; iirnpmpxcjwwcqosywx[o++] = (char)('0' + (bqsdygqhwtiyusknfrm % 10)); }
    }
    iirnpmpxcjwwcqosywx[o] = '\0';
    printf("%s %d\n", iirnpmpxcjwwcqosywx, o);
    return 0;
}
