#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x9F9 - 0x9F9), in_word = (0xCFB - 0xCFB), letters = (0xDA0 - 0xDA0);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x7AE279D7 ^ 0x7AE279D7); }
        else { if (!in_word) { words++; in_word = (0x2951BADB ^ 0x2951BADA); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x2712BF19 ^ 0x2712BF19);
}
