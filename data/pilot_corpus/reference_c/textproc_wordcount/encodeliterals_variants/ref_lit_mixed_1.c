#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0xE6D - 0xE6D), in_word = (0x9DD - 0x9DD), letters = (0x2DF98000 ^ 0x2DF98000);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x545 - 0x545); }
        else { if (!in_word) { words++; in_word = (0x64E34E8C ^ 0x64E34E8D); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x6FEDE170 ^ 0x6FEDE170);
}
