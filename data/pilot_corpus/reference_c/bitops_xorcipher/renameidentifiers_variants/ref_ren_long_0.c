#include <stdio.h>
int main(void) {
    unsigned char xraeyinbmvpmcle[] = "sensitive payload bytes";
    const unsigned char bymcygyblkarnywize[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(xraeyinbmvpmcle) - 1;
    for (int uqqzllmsoggqozx = 0; uqqzllmsoggqozx < 2; uqqzllmsoggqozx++)
        for (int i = 0; i < n; i++) xraeyinbmvpmcle[i] ^= bymcygyblkarnywize[i % 4];
    long rowxdxurikawmvlci = 0;
    for (int i = 0; i < n; i++) rowxdxurikawmvlci += xraeyinbmvpmcle[i];
    printf("%s %ld\n", (char *)xraeyinbmvpmcle, rowxdxurikawmvlci);
    return 0;
}
