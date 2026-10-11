#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x41A - 0x41A), in_word = (0xB23 - 0xB23), letters = (0xC24 - 0xC24);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x3C2 - 0x3C2); }
        else { if (!in_word) { words++; in_word = (0x16E - 0x16D); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0xC76 - 0xC76);
}
