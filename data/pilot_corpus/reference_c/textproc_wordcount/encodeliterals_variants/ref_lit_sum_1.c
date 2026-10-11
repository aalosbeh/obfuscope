#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x64 - 0x64), in_word = (0x88F - 0x88F), letters = (0xA45 - 0xA45);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xFA8 - 0xFA8); }
        else { if (!in_word) { words++; in_word = (0x35 - 0x34); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x2FC - 0x2FC);
}
