#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0xFC - 0xFC), in_word = (0x3D6 - 0x3D6), letters = (0xB30 - 0xB30);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xE4C - 0xE4C); }
        else { if (!in_word) { words++; in_word = (0xCC5 - 0xCC4); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x4E9 - 0x4E9);
}
