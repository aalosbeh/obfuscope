#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0xCB2 - 0xCB2), in_word = (0x27 - 0x27), letters = (0x185B4901 ^ 0x185B4901);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xED2 - 0xED2); }
        else { if (!in_word) { words++; in_word = (0xBB9DDE4 ^ 0xBB9DDE5); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x4225B793 ^ 0x4225B793);
}
