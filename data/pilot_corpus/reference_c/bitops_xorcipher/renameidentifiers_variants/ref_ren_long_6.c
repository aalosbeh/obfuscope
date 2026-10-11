#include <stdio.h>
int main(void) {
    unsigned char zqkchqhxqoeqvqidhwln[] = "sensitive payload bytes";
    const unsigned char wxxbqnjgehdxpjegn[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(zqkchqhxqoeqvqidhwln) - 1;
    for (int tgkzcipoqcwdcwkddjksim = 0; tgkzcipoqcwdcwkddjksim < 2; tgkzcipoqcwdcwkddjksim++)
        for (int i = 0; i < n; i++) zqkchqhxqoeqvqidhwln[i] ^= wxxbqnjgehdxpjegn[i % 4];
    long ysqbmpbtslcbeuyd = 0;
    for (int i = 0; i < n; i++) ysqbmpbtslcbeuyd += zqkchqhxqoeqvqidhwln[i];
    printf("%s %ld\n", (char *)zqkchqhxqoeqvqidhwln, ysqbmpbtslcbeuyd);
    return 0;
}
