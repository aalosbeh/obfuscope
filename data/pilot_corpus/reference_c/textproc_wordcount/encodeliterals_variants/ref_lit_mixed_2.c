#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x5104C6BE ^ 0x5104C6BE), in_word = (0xB3F - 0xB3F), letters = (0x1F5 - 0x1F5);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x11E69E75 ^ 0x11E69E75); }
        else { if (!in_word) { words++; in_word = (0xE7D - 0xE7C); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x5C9 - 0x5C9);
}
