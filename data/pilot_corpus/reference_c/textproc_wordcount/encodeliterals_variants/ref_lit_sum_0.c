#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x95B - 0x95B), in_word = (0xC96 - 0xC96), letters = (0x1AB - 0x1AB);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0xA6C - 0xA6C); }
        else { if (!in_word) { words++; in_word = (0xC01 - 0xC00); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x7A1 - 0x7A1);
}
