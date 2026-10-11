#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0xA45 - 0xA45), in_word = (0x7A8 - 0x7A8), letters = (0x628719C9 ^ 0x628719C9);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xAD2 - 0xAD2); }
        else { if (!in_word) { words++; in_word = (0x1B3432BF ^ 0x1B3432BE); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x174F98E2 ^ 0x174F98E2);
}
