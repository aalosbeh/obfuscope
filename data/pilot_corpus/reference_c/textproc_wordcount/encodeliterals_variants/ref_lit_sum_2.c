#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x18A - 0x18A), in_word = (0xF6F - 0xF6F), letters = (0xF2 - 0xF2);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x42D - 0x42D); }
        else { if (!in_word) { words++; in_word = (0x56E - 0x56D); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x4FE - 0x4FE);
}
