#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0xF60 - 0xF60), in_word = (0xAD4 - 0xAD4), letters = (0xF32 - 0xF32);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xB50 - 0xB50); }
        else { if (!in_word) { words++; in_word = (0x30 - 0x2F); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0xD77 - 0xD77);
}
