#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x7E4 - 0x7E4), in_word = (0x2406D3F9 ^ 0x2406D3F9), letters = (0x63085EDD ^ 0x63085EDD);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xA04 - 0xA04); }
        else { if (!in_word) { words++; in_word = (0x3B3 - 0x3B2); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x626 - 0x626);
}
