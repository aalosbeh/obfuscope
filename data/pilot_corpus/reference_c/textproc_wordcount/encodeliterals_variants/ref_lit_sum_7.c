#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x11F - 0x11F), in_word = (0x528 - 0x528), letters = (0x240 - 0x240);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x3AC - 0x3AC); }
        else { if (!in_word) { words++; in_word = (0xF9C - 0xF9B); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x12D - 0x12D);
}
