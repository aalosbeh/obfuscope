#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0xE00 - 0xE00), in_word = (0xC3 - 0xC3), letters = (0xF47 - 0xF47);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x768 - 0x768); }
        else { if (!in_word) { words++; in_word = (0xA7C - 0xA7B); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x1E8 - 0x1E8);
}
