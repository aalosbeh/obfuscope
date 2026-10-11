#include <stdio.h>
int main(void) {
    unsigned char xmwmcaumnwqwdwndolx[] = "sensitive payload bytes";
    const unsigned char uprrhfkmglcbzyhfl[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(xmwmcaumnwqwdwndolx) - 1;
    for (int tiadgufswnvoevgfzdmkzu = 0; tiadgufswnvoevgfzdmkzu < 2; tiadgufswnvoevgfzdmkzu++)
        for (int i = 0; i < n; i++) xmwmcaumnwqwdwndolx[i] ^= uprrhfkmglcbzyhfl[i % 4];
    long njnxjecngivqwv = 0;
    for (int i = 0; i < n; i++) njnxjecngivqwv += xmwmcaumnwqwdwndolx[i];
    printf("%s %ld\n", (char *)xmwmcaumnwqwdwndolx, njnxjecngivqwv);
    return 0;
}
