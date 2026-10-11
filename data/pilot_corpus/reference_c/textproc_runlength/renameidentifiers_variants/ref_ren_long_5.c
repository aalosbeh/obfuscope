#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char wiebixdvdovmncopkpdp[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int znygdfoycysjwmafjdgy = 0;
        while (in[i] == c) { znygdfoycysjwmafjdgy++; i++; }
        if (o < 60) { wiebixdvdovmncopkpdp[o++] = c; wiebixdvdovmncopkpdp[o++] = (char)('0' + (znygdfoycysjwmafjdgy % 10)); }
    }
    wiebixdvdovmncopkpdp[o] = '\0';
    printf("%s %d\n", wiebixdvdovmncopkpdp, o);
    return 0;
}
